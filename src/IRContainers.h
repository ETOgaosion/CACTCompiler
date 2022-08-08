#include "IRCode.h"
#include "IROperands.h"

#pragma once

struct loopinfo{
    int cyclelayer;
    int handled;
    int start;
    int end;
    std::vector<int> subloop;
    std::vector<int> pred;
    std::vector<IROperand *> loopsym;
};

class IRProgram;

/* IRCodes are stored in function, optimization units within a function */
class IRFunction {
private:
    std::string functionName;
    /* use unordered map: */
    /* To access elements, use iterator or use symbol name: */
    /* @usage: for (auto it : paramVariables) */
    /* @usage: paramVariables["a"] */
    /* To add elements, use its name as key: */
    /* @usage: paramVariables["a"] = new IRSymbolVariable(a, nullptr, false) */
    std::unordered_map<std::string, IRSymbolVariable *> paramVariables;     // param vars, belongs to symbolVar
    std::unordered_map<std::string, IRSymbolVariable *> localVariables;     // local vars, as symbolVar
    std::unordered_map<std::string, IRTempVariable *> tempVariables;        // temp vars, generated by compiler
    std::vector<IRCode *> codes;                                            // IRCodes
    std::unordered_map<std::string, IRLabel *> labels;                      // labels appearing in function, unique globally

    /* Optimization */
    std::vector<int> entrances;                                             // entrance offset in codes of each basic block
    std::vector<std::vector<IRCode *>> basicBlocks;                         // each codes inside are in a basic block
    std::vector<std::vector<int>> Pred;                                     // "Pred", which means blocks' id that each block can come from
    std::vector<std::vector<int>> controlFlow;                              // "control flow", which means blocks' id that each block can goto
    std::vector<int> cycleNum;                                              // the levels of cycle each block is in 
    std::vector<loopinfo> loop;
    std::vector<std::vector<int>> dom;

    /* live var analysis */
    std::vector<std::vector<IROperand*>> inVars;                            // live vars inward a function
    std::vector<std::vector<IROperand*>> outVars;                           // live vars outward a function
    std::vector<std::vector<IROperand*>> useVars;                           // a var used in a function and no more definitions
    std::vector<std::vector<IROperand*>> defVars;                           // a var defined in a function and not used yet

    int tempCount;                                                          // temp var counter, used for naming them
    int labelCount;                                                         // label counter, used for naming them
    int frameSize;                                                          // current function frame size

    SymbolTable *functionTable;                                             // current function equivalent symbolTable

public:
    IRProgram * ir;                                                         // parent pointer, used for search info

    IRFunction(std::string newFunctionName, SymbolTable *newFunctionTable);

    bool addParamVariable(IRSymbolVariable *newVariable);
    bool addLocalVariable(int block, IRSymbolVariable *newVariable);
    IRTempVariable *addTempVariable(MetaDataType newMetaDataType);
    IRTempVariable *addTempVariable(IROperand *parentSymbolVariable);
    IRSymbolVariable *addSymbolVariable(int block, AbstractSymbol *newSymbol, IROperand *initVal);
    IRLabel *addLabel();
    bool addCode(IRCode *newCode);
    bool addCodes(const std::vector<IRCode *>& newCodes);
    bool insertCode(IRCode *newCode, int pos) { codes.insert(codes.begin() + pos, newCode
        ); return true; };
    bool replaceCode(IRCode *newCode, int pos) { codes[pos] = newCode; return true; };
    int calFrameSize();
    int addFrameSize(int inFrameSize) { frameSize += inFrameSize; return frameSize; };

    /* divide basic blocks */
    void basicBlockDivision();

    /* const folding and broadcasting */
    IRValue* immAddSub(IROperand* op1, IROperand* op2, IROperation op);
    IRValue* immMov(IROperand* op1, IROperand* op2, IROperation op);
    IRValue* immMul(IROperand* op1, IROperand* op2);
    IRValue* immDiv(IROperand* op1, IROperand* op2);
    IRValue* immCmp(IROperand* op1, IROperand* op2, IROperation op);
    /*Constant propagation*/
    void def_use_list();
    int Replacewith(IRCode *I, IROperand *val);
    void EraseBB(int i);
    void constFolding();
    /*Common subexpression extraction*/
    void CSE();
    /*jumpthreading*/
    bool BBisinvalid(int i);
    void JumpThreading();
    /*Loop invariant*/
    int updateloop(int first, int end, int base);
    void LICM();
    void HoistOnLoop(loopinfo * currentloop);
    void Hoist(loopinfo * currentloop, IRCode * code_pos, int entrance);
    bool CanBeHoist(loopinfo * currentloop, IRCode * code_pos);

    /* tool functions */
    /* find and delete op in vector */
    void delOperandInVec(std::vector<IROperand*>& vars, IROperand* op);
    /* add operand in vector but no same insertion */
    void addOperandToVec(std::vector<IROperand*>& vars, IROperand* op);
    /* compare between two vectors */
    static bool cmpTwoInVars(std::vector<IROperand*> & vec1, std::vector<IROperand*> & vec2);
    /* swap operand of a code in exactly the same operation */
    static void substituteUseOp(IRCode* code, IROperand* dst_op, IROperand* cmp_op, IROperation op);

    /* live var analysis */
    void useDefVarsAnalysis();
    void liveVarAnalysis();

    /* dead code deletion */
    void delDeadCode() ;
    void ADCE();
    bool haveEffection(IROperation op);
    void FindLiveInst(IRCode* code,std::vector<IRCode *>& replaceinst);

    /* bind registers */
    /* calculate active regions of each var */
    void calVarActiveRegions();
    /* determine whether two vectors overlap(have some same numbers) */
    static bool vectorOverlap(const std::vector<int>& a, const std::vector<int>& b);
    /* calculate conflict between vars, each var conflicts with which other */
    std::unordered_map<IROperand *, std::vector<IROperand *>> calConflictVarRelations();
    /* calculate and color register graph, return two-dimension operands, operands in each outside vector do not conflict with each other */
    std::vector<std::vector<IROperand *>> calRegisterGraph(std::unordered_map<IROperand *, std::vector<IROperand *>> conflictVar);
    /* calculate variable costs, choose most-cost vars stored in register */
    std::unordered_map<IROperand *, int> calVarCosts();
    /* start bind function */
    void varBindRegisters(TargetCodes *t);

    /* optimization start function, start due to optimization level */
    void optimize(TargetCodes *t, int inOptimizeLevel);

    std::string getFunctionName() const;
    /* determine whether this function is provided by static library */
    bool getFunctionInLib() const;
    SymbolTable *getFuncSymbolTable() const { return functionTable; };
    IRSymbolVariable *getLocalVariable(int block, const std::string& varName);
    std::unordered_map<std::string, IRSymbolVariable *> getLocalVariables() { return localVariables; };
    IRSymbolVariable *getParamVariable(const std::string& varName);
    std::unordered_map<std::string, IRSymbolVariable *> getParamVariables() { return paramVariables; };
    IRTempVariable *getTempVariable(const std::string& varName);
    std::unordered_map<std::string, IRTempVariable *> getTempVariables() { return tempVariables; };
    IRCode *getCode(int cnt);
    std::vector<IRCode *> &getCodes();
    IRLabel *getLabel(const std::string& labelName);
    int getFrameSize() const;
    std::vector<Register *> getBindRegisters() const;

    void print(SymbolTable *globalSymbolTable) const;
    void targetCodeGen(TargetCodes * t);
};

/* functions stored in program */
class IRProgram {
private:
    IRProgram();
    SymbolTable *globalSymbolTable;                                         // global symbol table
    std::string programName;
    std::unordered_map<std::string, IRSymbolVariable *> globalVariables;    // global variables
    std::unordered_map<std::string, IRFunction *> functions;                // functions
    std::unordered_map<std::string, IRSymbolFunction *> funcSymbols;        // functions equivalent symbolFunction, for call instruction
    /* also use unordered map to store */
    /* key is actual value, to avoid repetition */
    /* @example: 1's key is "1", 0.99's key is "0.99", {1, 2, 3}'s key is "1,2,3" */
    std::unordered_map<std::string, IRValue *> immValues;                   // immediate value that must be stored globally

    int valueCount;                                                         // counter for immediate value, used for their label
    
public:
    static IRProgram *getIRProgram(std::string newProgramName, SymbolTable *newGlobalSymbolTable);
    void initializeFields(std::string newProgramName, SymbolTable *newGlobalSymbolTable);

    IRSymbolVariable *addGlobalVariable(AbstractSymbol *symbol, IROperand *newValue);
    bool addFunction(IRFunction *newFunction);
    bool addSymbolFunction(IRSymbolFunction *funcSymbol);
    IRValue *addImmValue(MetaDataType inMetaDataType, const std::string &inValue);
    IRValue *addImmValue(const std::string &inLabel, MetaDataType inMetaDataType, const std::string &inValue);
    IRValue *addMulSameImmValue(MetaDataType inMetaDataType, const std::string &inValue, const std::vector<std::size_t>& shape);
    IRValue *addMulImmValue(MetaDataType inMetaDataType, std::vector<std::string> &inValues);

    std::unordered_map<std::string, IRSymbolVariable *> getGlobalVariables() const {return globalVariables; };
    SymbolTable *getGlobalSymbolTable() const { return globalSymbolTable; };
    IRSymbolVariable *getGlobalVariable(const std::string& varName);
    IRFunction *getFunction(const std::string& functionName);
    IRSymbolFunction *getSymbolFunction(const std::string& functionName);
    IRValue *getImmValue(const std::string& inImmValue);
    IRValue *getImmValue(const std::vector<std::string>& inImmValues);

    void print();
    void write(const std::string &path);
    void targetGen(TargetCodes *t, int inOptimizeLevel);
    static void targetCodePrint(TargetCodes * t);
    static void targetCodeWrite(TargetCodes * t, std::string path);
};



