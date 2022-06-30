#include "IROperands.h"

#include <utility>
#include <sstream>
#include "tools.h"

using namespace std;

IRLabel::IRLabel(string newName) : IROperand(OperandType::LABEL) {
    labelName = std::move(newName);
}

void IRLabel::print() const {
    cout << "label: " << labelName <<endl;
}

string IRLabel::getVal() const {
    return labelName;
}

IRValue::IRValue(MetaDataType newMetaDataType, const string &newLabel, bool newIsArray) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values.clear();
    valueLabel = newLabel;
    isArray = newIsArray;
}

IRValue::IRValue(MetaDataType newMetaDataType, const std::string& newValue, const std::string &newLabel, bool newIsArray) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values.clear();
    values.push_back(newValue);
    valueLabel = newLabel;
    isArray = newIsArray;
}

IRValue::IRValue(MetaDataType newMetaDataType, const std::vector<std::string>& newValues, const string &newLabel, bool newIsArray) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    values.clear();
    for(const auto& newValue : newValues) {
        values.push_back(newValue);
    }
    valueLabel = newLabel;
    isArray = newIsArray;
}

void IRValue::addValue(const string& newValue) {
    values.push_back(newValue);
}

void IRValue::addValues(const std::vector<std::string>& newValues) {
    for(const auto& newValue : newValues) {
        values.push_back(newValue);
    }
    isArray = true;
}

Register *IRValue::load(TargetCodes *t) {
    MetaDataType dataType = metaDataType;
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    Register *retRegister = nullptr;
    if (valueLabel.empty()) {
        freeRegister = 
        t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        Register *zero = t->tryGetCertainRegister(true, "zero", hasFreeRegister);
        if (values.front() == "0") {
            t->addCodeMv(freeRegister, zero,FloatPointType::NONE, FloatPointType::NONE);
        }
        else {
            t->addCodeAddi(freeRegister, zero, stoi(values.front()), FloatPointType::NONE);
        }
        t->setRegisterFree(true, zero);
        return freeRegister;
    }
    else {
        switch(dataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                return freeRegister;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                retRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
                t->addCodeMv(retRegister, freeRegister, FloatPointType::SINGLE, FloatPointType::NONE);
                return retRegister;
            case MetaDataType::DOUBLE:
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                retRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
                t->addCodeMv(retRegister, freeRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
                return retRegister;
        }
    }
}

Register *IRValue::loadTo(TargetCodes *t, const std::string &regName) {
    MetaDataType dataType = metaDataType;
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    Register *targetRegister = nullptr;
    if (valueLabel.empty()) {
        targetRegister = 
        t->tryGetCertainRegister(true, regName, hasFreeRegister);
        Register *zero = t->tryGetCertainRegister(true, "zero", hasFreeRegister);
        if (values.front() == "0") {
            t->addCodeMv(targetRegister, zero,FloatPointType::NONE, FloatPointType::NONE);
        }
        else {
            t->addCodeAddi(targetRegister, zero, stoi(values.front()), FloatPointType::NONE);
        }
        t->setRegisterFree(true, zero);
        return targetRegister;
    }
    else {
        switch(dataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLi(targetRegister, valueLabel);
                return targetRegister;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeMv(targetRegister, freeRegister, FloatPointType::SINGLE, FloatPointType::NONE);
                return targetRegister;
            case MetaDataType::DOUBLE:
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeMv(targetRegister, freeRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
                return targetRegister;
        }
    }
}

Register *IRValue::loadTo(TargetCodes *t, Register *inReg) {
    MetaDataType dataType = metaDataType;
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    if (valueLabel.empty()) {
        Register *zero = t->tryGetCertainRegister(true, "zero", hasFreeRegister);
        if (values.front() == "0") {
            t->addCodeMv(inReg, zero, FloatPointType::NONE, FloatPointType::NONE);
        }
        else {
            t->addCodeAddi(inReg, zero, stoi(values.front()), FloatPointType::NONE);
        }
        t->setRegisterFree(true, zero);
        return inReg;
    }
    else {
        switch(dataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                t->addCodeLi(inReg, valueLabel);
                return inReg;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                t->addCodeMv(inReg, freeRegister, FloatPointType::SINGLE, FloatPointType::NONE);
                return inReg;
            case MetaDataType::DOUBLE:
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLi(freeRegister, valueLabel);
                t->addCodeMv(inReg, freeRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
                return inReg;
        }
    }
}

void IRValue::print() const {
    if (!valueLabel.empty()) {
        cout << valueLabel << ": ";
    }
    if (isArray) {
        cout << "{";
        for (auto value : std::vector<string>(values.begin(), values.end() - 1)) {
            cout << value << ", ";
        }
        cout << values.back();
        cout << "}";
    }
    else {
        cout << values.front();
    }
    cout << endl;
}

string IRValue::getVal() const {
    string retVal = {};
    if (!valueLabel.empty()) {
        retVal += (valueLabel + ": ");
    }
    if (isArray) {
        retVal += "{";
        for (auto value : std::vector<string>(values.begin(), values.end() - 1)) {
            retVal += (value + ", ");
        }
        retVal += values.back();
        retVal += "}";
    }
    else {
        retVal += values.front();
    }
    return retVal;
}

void IRValue::genTargetValue(TargetCodes *t) const {
    stringstream stream;
    if (values.size() == 1) {
        stream << "\t.equ\t" << valueLabel << ", ";
        switch (metaDataType) {
            case MetaDataType::INT:
                stream << "0x" << std::hex << stoi(values.front());
                break;
            case MetaDataType::FLOAT:
                stream << Tools::ftoIEEE754s(stof(values.front()));
                break;
            case MetaDataType::DOUBLE:
                stream << Tools::dtoIEEE754s(stod(values.front()));
                break;
        }
        stream << endl;
    }
    else {
        t->addCodeLabel(valueLabel);
        for (const auto& value : values) {
            stream << "\t.word\t";
            switch (metaDataType) {
                case MetaDataType::INT:
                    stream << "0x" << std::hex << stoi(value);
                    break;
                case MetaDataType::FLOAT:
                    stream << Tools::ftoIEEE754s(stof(value));
                    break;
                case MetaDataType::DOUBLE:
                    stream << Tools::dtoIEEE754s(stod(value));
                    break;
            }
            stream << endl;
        }
    }
    t->addCodeDirectives(stream.str());
}

IRSymbolVariable::IRSymbolVariable(AbstractSymbol *newSymbol, IRValue *newValue, bool newIsGlobalSymbolVar) : IROperand(OperandType::SYMBOLVAR) {
    symbol = newSymbol;
    assigned = false;
    historySymbols.clear();
    initialValue = newValue;
    isGlobalSymbolVar = newIsGlobalSymbolVar;
}

Register *IRSymbolVariable::load(TargetCodes *t) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    Register *freeRegister = nullptr;
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(dataType) {
            case MetaDataType::BOOL:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLb(freeRegister, sp, -symbol->getOffset(), FloatPointType::NONE);
                break;
            case MetaDataType::INT:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLw(freeRegister, sp, -symbol->getOffset(), FloatPointType::NONE);
                break;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
                t->addCodeFlw(freeRegister, sp, -symbol->getOffset());
                break;
            case MetaDataType::DOUBLE:
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
                t->addCodeFld(freeRegister, sp, -symbol->getOffset());
                break;
        }
        t->setRegisterFree(true, sp);
    }
    else {
        Register *tmpRegister = nullptr;
        switch(dataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLla(freeRegister, symbol->getSymbolName());
                break;
            case MetaDataType::FLOAT:
                tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
                t->addCodeLla(tmpRegister, symbol->getSymbolName());
                t->addCodeMv(freeRegister, tmpRegister, FloatPointType::SINGLE, FloatPointType::NONE);
                t->setRegisterFree(true, tmpRegister);
                break;
            case MetaDataType::DOUBLE:
                tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
                t->addCodeLla(tmpRegister, symbol->getSymbolName());
                t->addCodeMv(freeRegister, tmpRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
                t->setRegisterFree(true, tmpRegister);
                break;
        }
    }
    return freeRegister;
}

Register *IRSymbolVariable::loadTo(TargetCodes *t, const std::string &regName) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    Register *targetRegister = nullptr;
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(dataType) {
            case MetaDataType::BOOL:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLb(targetRegister, sp, -symbol->getOffset(), FloatPointType::NONE);
                break;
            case MetaDataType::INT:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLw(targetRegister, sp, -symbol->getOffset(), FloatPointType::NONE);
                break;
            case MetaDataType::FLOAT:
                targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                t->addCodeFlw(targetRegister, sp, -symbol->getOffset());
                break;
            case MetaDataType::DOUBLE:
                targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                t->addCodeFld(targetRegister, sp, -symbol->getOffset());
                break;
        }
        t->setRegisterFree(true, sp);
    }
    else {
        Register *tmpRegister = nullptr;
        switch(dataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLla(targetRegister, symbol->getSymbolName());
                break;
            case MetaDataType::FLOAT:
                tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLla(tmpRegister, symbol->getSymbolName());
                t->addCodeMv(targetRegister, tmpRegister, FloatPointType::SINGLE, FloatPointType::NONE);
                t->setRegisterFree(true, tmpRegister);
                break;
            case MetaDataType::DOUBLE:
                tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLla(tmpRegister, symbol->getSymbolName());
                t->addCodeMv(targetRegister, tmpRegister, FloatPointType::DOUBLE, FloatPointType::NONE);
                t->setRegisterFree(true,tmpRegister);
                break;
        }
    }
    return targetRegister;
}

Register *IRSymbolVariable::loadTo(TargetCodes *t, Register *inReg) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(dataType) {
            case MetaDataType::BOOL:
                t->addCodeLb(inReg, sp, -symbol->getOffset(), FloatPointType::NONE);
                break;
            case MetaDataType::INT:
                t->addCodeLw(inReg, sp, -symbol->getOffset(), FloatPointType::NONE);
                break;
            case MetaDataType::FLOAT:
                t->addCodeFlw(inReg, sp, -symbol->getOffset());
                break;
            case MetaDataType::DOUBLE:
                t->addCodeFld(inReg, sp, -symbol->getOffset());
                break;
        }
        t->setRegisterFree(true, sp);
    }
    else {
        switch (inReg->getFloatPointType()) {
            case FloatPointType::NONE:
                t->addCodeLla(inReg, symbol->getSymbolName());
                break;
            case FloatPointType::SINGLE:
            case FloatPointType::DOUBLE:
                Register *tmpRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLla(tmpRegister, symbol->getSymbolName());
                t->addCodeMv(inReg, tmpRegister, inReg->getFloatPointType(), FloatPointType::NONE);
                t->setRegisterFree(true, tmpRegister);
                break;
        }
    }
    return inReg;
}

void IRSymbolVariable::storeFrom(TargetCodes *t, Register *reg) {
    MetaDataType dataType = symbol->getMetaDataType();
    bool hasFreeRegister;
    if (!isGlobalSymbolVar) {
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(dataType) {
            case MetaDataType::BOOL:
                t->addCodeSb(sp, reg, -symbol->getOffset(), FloatPointType::NONE);
                break;
            case MetaDataType::INT:
                t->addCodeSw(sp, reg, -symbol->getOffset(), FloatPointType::NONE);
                break;
            case MetaDataType::FLOAT:
                t->addCodeFsw(sp, reg, -symbol->getOffset());
                break;
            case MetaDataType::DOUBLE:
                t->addCodeFsd(sp, reg, -symbol->getOffset());
                break;
        }
        t->setRegisterFree(true, sp);
    }
    else {
        Register *freeReg = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
        switch (reg->getFloatPointType()) {
            case FloatPointType::NONE:
                t->addCodeLla(freeReg, symbol->getSymbolName());
                t->addCodeSw(freeReg, reg, 0, FloatPointType::NONE);
                break;
            case FloatPointType::SINGLE:
                t->addCodeLla(freeReg, symbol->getSymbolName());
                t->addCodeFsw(freeReg, reg, 0);
                break;
            case FloatPointType::DOUBLE:
                t->addCodeLla(freeReg, symbol->getSymbolName());
                t->addCodeFsd(freeReg, reg, 0);
                break;
        }
        t->setRegisterFree(true, freeReg);
    }
}

void IRSymbolVariable::print() const {
    cout << symbol->getSymbolName() << " := symbol type: " << static_cast<int>(symbol->getSymbolType()) << "; data type: " << static_cast<int>(symbol->getMetaDataType());
    if (initialValue) {
        cout << "; initValue: ";
        initialValue->print();
    }
    cout << endl;
}

string IRSymbolVariable::getVal() const {
    return symbol->getSymbolName();
}

void IRSymbolVariable::genTargetValue(TargetCodes *t) const {
    stringstream stream;
    vector<string> values = initialValue->getValues();
    if (values.size() == 1) {
        stream << "\t.equ\t" << initialValue->getValueLabel() << ", ";
        switch (initialValue->getMetaDataType()) {
            case MetaDataType::INT:
                stream << "0x" << std::hex << stoi(values.front());
                break;
            case MetaDataType::FLOAT:
                stream << Tools::ftoIEEE754s(stof(values.front()));
                break;
            case MetaDataType::DOUBLE:
                stream << Tools::dtoIEEE754s(stod(values.front()));
                break;
        }
        stream << endl;
    }
    else {
        t->addCodeLabel(initialValue->getValueLabel());
        for (const auto& value : values) {
            stream << "\t.word\t";
            switch (initialValue->getMetaDataType()) {
                case MetaDataType::INT:
                    stream << "0x" << std::hex << stoi(value);
                    break;
                case MetaDataType::FLOAT:
                    stream << Tools::ftoIEEE754s(stof(value));
                    break;
                case MetaDataType::DOUBLE:
                    stream << Tools::dtoIEEE754s(stod(value));
                    break;
            }
            stream << endl;
        }
    }
    t->addCodeDirectives(stream.str());
}

void IRSymbolVariable::genTargetGlobalValue(TargetCodes *t) const {
    stringstream stream;
    vector<string> values = initialValue->getValues();
    if (values.size() == 1) {
        t->addCodeLabel(initialValue->getValueLabel());
        stream << "\t.word\t";
        switch (initialValue->getMetaDataType()) {
            case MetaDataType::INT:
                stream << "0x" << std::hex << stoi(values.front());
                break;
            case MetaDataType::FLOAT:
                stream << Tools::ftoIEEE754s(stof(values.front()));
                break;
            case MetaDataType::DOUBLE:
                stream << Tools::dtoIEEE754s(stod(values.front()));
                break;
        }
        stream << endl;
    }
    else {
        t->addCodeLabel(initialValue->getValueLabel());
        for (const auto& value : values) {
            stream << "\t.word\t";
            switch (initialValue->getMetaDataType()) {
                case MetaDataType::INT:
                    stream << "0x" << std::hex << stoi(value);
                    break;
                case MetaDataType::FLOAT:
                    stream << Tools::ftoIEEE754s(stof(value));
                    break;
                case MetaDataType::DOUBLE:
                    stream << Tools::dtoIEEE754s(stod(value));
                    break;
            }
            stream << endl;
        }
    }
    t->addCodeDirectives(stream.str());
}

IRSymbolFunction::IRSymbolFunction(SymbolTable *function) : IROperand(OperandType::SYMBOLFUNC) {
    functionTable = function;
}

void IRSymbolFunction::print() const {
    cout << functionTable->getFuncName() << "(";
    auto paramTypeList = functionTable->getParamDataTypeList();
    for (auto param : vector<tuple<MetaDataType, bool, size_t>>(paramTypeList.begin(), paramTypeList.end() - 1)) {
        cout << static_cast<int>(get<0>(param));
        if (get<1>(param)) {
            cout << "[" << get<2>(param) << "]";
        }
        cout << ",";
    }
    auto param = paramTypeList.back();
    cout << static_cast<int>(get<0>(param));
    if (get<1>(param)) {
        cout << "[" << get<2>(param) << "]";
    }
    cout << ") => " << static_cast<int>(functionTable->getReturnType()) << "\n";
}

string IRSymbolFunction::getVal() const {
    return functionTable->getFuncName();
}



IRTempVariable::IRTempVariable(string newName, MetaDataType newMetaDataType) : IROperand(OperandType::TEMPVAR) {
    symbolName = std::move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    aliasToSymbol = false;
    symbolVariable = nullptr;
    offset = 0;
    initialValue = nullptr;
}

IRTempVariable::IRTempVariable(std::string newName, MetaDataType newMetaDataType, IROperand *parentVariable) : IROperand(OperandType::TEMPVAR) {
    symbolName = std::move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    aliasToSymbol = true;
    symbolVariable = parentVariable;
    offset = 0;
    initialValue = nullptr;
}

IRTempVariable::IRTempVariable(std::string newName, MetaDataType newMetaDataType, IRValue *newValue) : IROperand(OperandType::TEMPVAR) {
    symbolName = std::move(newName);
    metaDataType = newMetaDataType;
    assigned = false;
    aliasToSymbol = false;
    symbolVariable = nullptr;
    offset = 0;
    initialValue = newValue;
}


Register *IRTempVariable::load(TargetCodes *t) {
    if (!aliasToSymbol) {
        bool hasFreeRegister;
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        Register *freeRegister = nullptr;
        switch(metaDataType) {
            case MetaDataType::BOOL:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLb(freeRegister, sp, -offset, FloatPointType::NONE);
                break;
            case MetaDataType::INT:
                freeRegister = t->getNextFreeRegister(true, false, FloatPointType::NONE, hasFreeRegister);
                t->addCodeLw(freeRegister, sp, -offset, FloatPointType::NONE);
                break;
            case MetaDataType::FLOAT:
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::SINGLE, hasFreeRegister);
                t->addCodeFlw(freeRegister, sp, -offset);
                break;
            case MetaDataType::DOUBLE:
                freeRegister = t->getNextFreeRegister(false, false, FloatPointType::DOUBLE, hasFreeRegister);
                t->addCodeFld(freeRegister, sp, -offset);
                break;
        }
        t->setRegisterFree(true, sp);
        return freeRegister;
    }
    else {
        return symbolVariable->load(t);
    }
}

Register *IRTempVariable::loadTo(TargetCodes *t, const std::string &regName) {
    if (!aliasToSymbol) {
        bool hasFreeRegister;
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        Register *targetRegister = nullptr;
        switch(metaDataType) {
            case MetaDataType::BOOL:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLb(targetRegister, sp, -offset, FloatPointType::NONE);
                break;
            case MetaDataType::INT:
                targetRegister = t->tryGetCertainRegister(true, regName, hasFreeRegister);
                t->addCodeLw(targetRegister, sp, -offset, FloatPointType::NONE);
                break;
            case MetaDataType::FLOAT:
                targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                t->addCodeFlw(targetRegister, sp, -offset);
                break;
            case MetaDataType::DOUBLE:
                targetRegister = t->tryGetCertainRegister(false, regName, hasFreeRegister);
                t->addCodeFld(targetRegister, sp, -offset);
                break;
        }
        t->setRegisterFree(true, sp);
        return targetRegister;
    }
    else {
        return symbolVariable->loadTo(t, regName);
    }
}

Register *IRTempVariable::loadTo(TargetCodes *t, Register *inReg) {
    if (!aliasToSymbol) {
        bool hasFreeRegister;
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch (metaDataType) {
            case MetaDataType::BOOL:
            case MetaDataType::INT:
                t->addCodeLw(inReg, sp, -offset, FloatPointType::NONE);
                break;
            case MetaDataType::FLOAT:
                t->addCodeFlw(inReg, sp, -offset);
            case MetaDataType::DOUBLE:
                t->addCodeFld(inReg, sp, -offset);
        }
        t->setRegisterFree(true, sp);
        return inReg;
    }
    else {
        return symbolVariable->loadTo(t, inReg);
    }
}

void IRTempVariable::storeFrom(TargetCodes *t, Register *reg) {
    if (!aliasToSymbol) {
        bool hasFreeRegister;
        Register *sp = t->tryGetCertainRegister(true, "sp", hasFreeRegister);
        switch(metaDataType) {
            case MetaDataType::BOOL:
                t->addCodeSb(sp, reg, -offset, FloatPointType::NONE);
                break;
            case MetaDataType::INT:
                t->addCodeSw(sp, reg, -offset, FloatPointType::NONE);
                break;
            case MetaDataType::FLOAT:
                t->addCodeFsw(sp, reg, -offset);
                break;
            case MetaDataType::DOUBLE:
                t->addCodeFsd(sp, reg, -offset);
                break;
        }
        t->setRegisterFree(true, sp);
    }
    else {
        return symbolVariable->storeFrom(t, reg);
    }
}

void IRTempVariable::print() const {
    if (!aliasToSymbol) {
        cout << symbolName << ":= symbol type: TEMP VAR; data type: " << static_cast<int>(metaDataType);
        if (initialValue) {
            cout << "; initValue: ";
            initialValue->print();
        }
        cout << endl;
    }
}

string IRTempVariable::getVal() const {
    return symbolName;
}