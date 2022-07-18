
    #include "../src/SymbolTable.h"
    #include "../src/IROperands.h"
    #include "../src/IRCode.h"
    #include <vector>
    #include <unordered_map>


// Generated from grammar/SysY.g4 by ANTLR 4.8


#include "SysYListener.h"

#include "SysYParser.h"


using namespace antlrcpp;
using namespace antlr4;

SysYParser::SysYParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SysYParser::~SysYParser() {
  delete _interpreter;
}

std::string SysYParser::getGrammarFileName() const {
  return "SysY.g4";
}

const std::vector<std::string>& SysYParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SysYParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompUnitContext ------------------------------------------------------------------

SysYParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::CompUnitContext::EOF() {
  return getToken(SysYParser::EOF, 0);
}

std::vector<SysYParser::DeclContext *> SysYParser::CompUnitContext::decl() {
  return getRuleContexts<SysYParser::DeclContext>();
}

SysYParser::DeclContext* SysYParser::CompUnitContext::decl(size_t i) {
  return getRuleContext<SysYParser::DeclContext>(i);
}

std::vector<SysYParser::FuncDefContext *> SysYParser::CompUnitContext::funcDef() {
  return getRuleContexts<SysYParser::FuncDefContext>();
}

SysYParser::FuncDefContext* SysYParser::CompUnitContext::funcDef(size_t i) {
  return getRuleContext<SysYParser::FuncDefContext>(i);
}


size_t SysYParser::CompUnitContext::getRuleIndex() const {
  return SysYParser::RuleCompUnit;
}

void SysYParser::CompUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompUnit(this);
}

void SysYParser::CompUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompUnit(this);
}

SysYParser::CompUnitContext* SysYParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, SysYParser::RuleCompUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(80);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(78);
        decl();
        break;
      }

      case 2: {
        setState(79);
        funcDef();
        break;
      }

      }
      setState(82); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__0)
      | (1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__4)
      | (1ULL << SysYParser::T__12))) != 0));
    setState(84);
    match(SysYParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

SysYParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstDeclContext* SysYParser::DeclContext::constDecl() {
  return getRuleContext<SysYParser::ConstDeclContext>(0);
}

SysYParser::VarDeclContext* SysYParser::DeclContext::varDecl() {
  return getRuleContext<SysYParser::VarDeclContext>(0);
}


size_t SysYParser::DeclContext::getRuleIndex() const {
  return SysYParser::RuleDecl;
}

void SysYParser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void SysYParser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}

SysYParser::DeclContext* SysYParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, SysYParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(88);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(86);
        constDecl();
        break;
      }

      case SysYParser::T__3:
      case SysYParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(87);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

SysYParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::ConstDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

std::vector<SysYParser::ConstDefContext *> SysYParser::ConstDeclContext::constDef() {
  return getRuleContexts<SysYParser::ConstDefContext>();
}

SysYParser::ConstDefContext* SysYParser::ConstDeclContext::constDef(size_t i) {
  return getRuleContext<SysYParser::ConstDefContext>(i);
}


size_t SysYParser::ConstDeclContext::getRuleIndex() const {
  return SysYParser::RuleConstDecl;
}

void SysYParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void SysYParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}

SysYParser::ConstDeclContext* SysYParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, SysYParser::RuleConstDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(SysYParser::T__0);
    setState(91);
    bType();
    setState(92);
    constDef();
    setState(97);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(93);
      match(SysYParser::T__1);
      setState(94);
      constDef();
      setState(99);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(100);
    match(SysYParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

SysYParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::BTypeContext::getRuleIndex() const {
  return SysYParser::RuleBType;
}

void SysYParser::BTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBType(this);
}

void SysYParser::BTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBType(this);
}

SysYParser::BTypeContext* SysYParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, SysYParser::RuleBType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    _la = _input->LA(1);
    if (!(_la == SysYParser::T__3

    || _la == SysYParser::T__4)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

SysYParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::ConstDefContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

std::vector<SysYParser::ConstExpContext *> SysYParser::ConstDefContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::ConstDefContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

SysYParser::ConstInitValContext* SysYParser::ConstDefContext::constInitVal() {
  return getRuleContext<SysYParser::ConstInitValContext>(0);
}


size_t SysYParser::ConstDefContext::getRuleIndex() const {
  return SysYParser::RuleConstDef;
}

void SysYParser::ConstDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDef(this);
}

void SysYParser::ConstDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDef(this);
}

SysYParser::ConstDefContext* SysYParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 8, SysYParser::RuleConstDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(SysYParser::Ident);
    setState(111);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__5) {
      setState(105);
      match(SysYParser::T__5);
      setState(106);
      constExp();
      setState(107);
      match(SysYParser::T__6);
      setState(113);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(116);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__7) {
      setState(114);
      match(SysYParser::T__7);
      setState(115);
      constInitVal();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

SysYParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::ConstInitValContext::getRuleIndex() const {
  return SysYParser::RuleConstInitVal;
}

void SysYParser::ConstInitValContext::copyFrom(ConstInitValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
  this->shape = ctx->shape;
  this->isArray = ctx->isArray;
  this->value = ctx->value;
}

//----------------- ConstInitValOfVarContext ------------------------------------------------------------------

SysYParser::ConstExpContext* SysYParser::ConstInitValOfVarContext::constExp() {
  return getRuleContext<SysYParser::ConstExpContext>(0);
}

SysYParser::ConstInitValOfVarContext::ConstInitValOfVarContext(ConstInitValContext *ctx) { copyFrom(ctx); }

void SysYParser::ConstInitValOfVarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitValOfVar(this);
}
void SysYParser::ConstInitValOfVarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitValOfVar(this);
}
//----------------- ConstInitValOfArrayContext ------------------------------------------------------------------

std::vector<SysYParser::ConstExpContext *> SysYParser::ConstInitValOfArrayContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::ConstInitValOfArrayContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

SysYParser::ConstInitValOfArrayContext::ConstInitValOfArrayContext(ConstInitValContext *ctx) { copyFrom(ctx); }

void SysYParser::ConstInitValOfArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstInitValOfArray(this);
}
void SysYParser::ConstInitValOfArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstInitValOfArray(this);
}
SysYParser::ConstInitValContext* SysYParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 10, SysYParser::RuleConstInitVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(131);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::IntConst:
      case SysYParser::FloatConst: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<SysYParser::ConstInitValOfVarContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(118);
        constExp();
        break;
      }

      case SysYParser::T__8: {
        _localctx = dynamic_cast<ConstInitValContext *>(_tracker.createInstance<SysYParser::ConstInitValOfArrayContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(119);
        match(SysYParser::T__8);
        setState(128);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SysYParser::IntConst

        || _la == SysYParser::FloatConst) {
          setState(120);
          constExp();
          setState(125);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SysYParser::T__1) {
            setState(121);
            match(SysYParser::T__1);
            setState(122);
            constExp();
            setState(127);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(130);
        match(SysYParser::T__9);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

SysYParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::VarDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

std::vector<SysYParser::VarDefContext *> SysYParser::VarDeclContext::varDef() {
  return getRuleContexts<SysYParser::VarDefContext>();
}

SysYParser::VarDefContext* SysYParser::VarDeclContext::varDef(size_t i) {
  return getRuleContext<SysYParser::VarDefContext>(i);
}


size_t SysYParser::VarDeclContext::getRuleIndex() const {
  return SysYParser::RuleVarDecl;
}

void SysYParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void SysYParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

SysYParser::VarDeclContext* SysYParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, SysYParser::RuleVarDecl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    bType();
    setState(134);
    varDef();
    setState(139);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(135);
      match(SysYParser::T__1);
      setState(136);
      varDef();
      setState(141);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(142);
    match(SysYParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

SysYParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::VarDefContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

std::vector<SysYParser::ConstExpContext *> SysYParser::VarDefContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::VarDefContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}

SysYParser::InitValContext* SysYParser::VarDefContext::initVal() {
  return getRuleContext<SysYParser::InitValContext>(0);
}


size_t SysYParser::VarDefContext::getRuleIndex() const {
  return SysYParser::RuleVarDef;
}

void SysYParser::VarDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDef(this);
}

void SysYParser::VarDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDef(this);
}

SysYParser::VarDefContext* SysYParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 14, SysYParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(SysYParser::Ident);
    setState(151);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__5) {
      setState(145);
      match(SysYParser::T__5);
      setState(146);
      constExp();
      setState(147);
      match(SysYParser::T__6);
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__7) {
      setState(154);
      match(SysYParser::T__7);
      setState(155);
      initVal();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitValContext ------------------------------------------------------------------

SysYParser::InitValContext::InitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ExpContext* SysYParser::InitValContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

std::vector<SysYParser::InitValContext *> SysYParser::InitValContext::initVal() {
  return getRuleContexts<SysYParser::InitValContext>();
}

SysYParser::InitValContext* SysYParser::InitValContext::initVal(size_t i) {
  return getRuleContext<SysYParser::InitValContext>(i);
}


size_t SysYParser::InitValContext::getRuleIndex() const {
  return SysYParser::RuleInitVal;
}

void SysYParser::InitValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitVal(this);
}

void SysYParser::InitValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitVal(this);
}

SysYParser::InitValContext* SysYParser::initVal() {
  InitValContext *_localctx = _tracker.createInstance<InitValContext>(_ctx, getState());
  enterRule(_localctx, 16, SysYParser::RuleInitVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__10:
      case SysYParser::T__19:
      case SysYParser::T__20:
      case SysYParser::T__21:
      case SysYParser::Ident:
      case SysYParser::IntConst:
      case SysYParser::FloatConst: {
        enterOuterAlt(_localctx, 1);
        setState(158);
        exp();
        break;
      }

      case SysYParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(159);
        match(SysYParser::T__8);
        setState(168);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SysYParser::T__8)
          | (1ULL << SysYParser::T__10)
          | (1ULL << SysYParser::T__19)
          | (1ULL << SysYParser::T__20)
          | (1ULL << SysYParser::T__21)
          | (1ULL << SysYParser::Ident)
          | (1ULL << SysYParser::IntConst)
          | (1ULL << SysYParser::FloatConst))) != 0)) {
          setState(160);
          initVal();
          setState(165);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SysYParser::T__1) {
            setState(161);
            match(SysYParser::T__1);
            setState(162);
            initVal();
            setState(167);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(170);
        match(SysYParser::T__9);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

SysYParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::FuncTypeContext* SysYParser::FuncDefContext::funcType() {
  return getRuleContext<SysYParser::FuncTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncDefContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

SysYParser::FuncBlockContext* SysYParser::FuncDefContext::funcBlock() {
  return getRuleContext<SysYParser::FuncBlockContext>(0);
}

SysYParser::FuncFParamsContext* SysYParser::FuncDefContext::funcFParams() {
  return getRuleContext<SysYParser::FuncFParamsContext>(0);
}


size_t SysYParser::FuncDefContext::getRuleIndex() const {
  return SysYParser::RuleFuncDef;
}

void SysYParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void SysYParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}

SysYParser::FuncDefContext* SysYParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 18, SysYParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    funcType();
    setState(174);
    match(SysYParser::Ident);
    setState(175);
    match(SysYParser::T__10);
    setState(177);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__3

    || _la == SysYParser::T__4) {
      setState(176);
      funcFParams();
    }
    setState(179);
    match(SysYParser::T__11);
    setState(180);
    funcBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

SysYParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::FuncTypeContext::getRuleIndex() const {
  return SysYParser::RuleFuncType;
}

void SysYParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void SysYParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}

SysYParser::FuncTypeContext* SysYParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, SysYParser::RuleFuncType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__4)
      | (1ULL << SysYParser::T__12))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

SysYParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::FuncFParamContext *> SysYParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<SysYParser::FuncFParamContext>();
}

SysYParser::FuncFParamContext* SysYParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<SysYParser::FuncFParamContext>(i);
}


size_t SysYParser::FuncFParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncFParams;
}

void SysYParser::FuncFParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParams(this);
}

void SysYParser::FuncFParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParams(this);
}

SysYParser::FuncFParamsContext* SysYParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 22, SysYParser::RuleFuncFParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    funcFParam();
    setState(189);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(185);
      match(SysYParser::T__1);
      setState(186);
      funcFParam();
      setState(191);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

SysYParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::FuncFParamContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncFParamContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

SysYParser::BracketsContext* SysYParser::FuncFParamContext::brackets() {
  return getRuleContext<SysYParser::BracketsContext>(0);
}


size_t SysYParser::FuncFParamContext::getRuleIndex() const {
  return SysYParser::RuleFuncFParam;
}

void SysYParser::FuncFParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncFParam(this);
}

void SysYParser::FuncFParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncFParam(this);
}

SysYParser::FuncFParamContext* SysYParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 24, SysYParser::RuleFuncFParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    bType();
    setState(193);
    match(SysYParser::Ident);
    setState(195);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__5) {
      setState(194);
      brackets();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BracketsContext ------------------------------------------------------------------

SysYParser::BracketsContext::BracketsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::ExpContext *> SysYParser::BracketsContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::BracketsContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}


size_t SysYParser::BracketsContext::getRuleIndex() const {
  return SysYParser::RuleBrackets;
}

void SysYParser::BracketsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBrackets(this);
}

void SysYParser::BracketsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBrackets(this);
}

SysYParser::BracketsContext* SysYParser::brackets() {
  BracketsContext *_localctx = _tracker.createInstance<BracketsContext>(_ctx, getState());
  enterRule(_localctx, 26, SysYParser::RuleBrackets);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(197);
    match(SysYParser::T__5);
    setState(198);
    match(SysYParser::T__6);
    setState(205);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__5) {
      setState(199);
      match(SysYParser::T__5);
      setState(200);
      exp();
      setState(201);
      match(SysYParser::T__6);
      setState(207);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBlockContext ------------------------------------------------------------------

SysYParser::FuncBlockContext::FuncBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::FuncBlockItemContext *> SysYParser::FuncBlockContext::funcBlockItem() {
  return getRuleContexts<SysYParser::FuncBlockItemContext>();
}

SysYParser::FuncBlockItemContext* SysYParser::FuncBlockContext::funcBlockItem(size_t i) {
  return getRuleContext<SysYParser::FuncBlockItemContext>(i);
}


size_t SysYParser::FuncBlockContext::getRuleIndex() const {
  return SysYParser::RuleFuncBlock;
}

void SysYParser::FuncBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncBlock(this);
}

void SysYParser::FuncBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncBlock(this);
}

SysYParser::FuncBlockContext* SysYParser::funcBlock() {
  FuncBlockContext *_localctx = _tracker.createInstance<FuncBlockContext>(_ctx, getState());
  enterRule(_localctx, 28, SysYParser::RuleFuncBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(208);
    match(SysYParser::T__8);
    setState(212);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__0)
      | (1ULL << SysYParser::T__2)
      | (1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__4)
      | (1ULL << SysYParser::T__8)
      | (1ULL << SysYParser::T__10)
      | (1ULL << SysYParser::T__13)
      | (1ULL << SysYParser::T__15)
      | (1ULL << SysYParser::T__16)
      | (1ULL << SysYParser::T__19)
      | (1ULL << SysYParser::T__20)
      | (1ULL << SysYParser::T__21)
      | (1ULL << SysYParser::Ident)
      | (1ULL << SysYParser::IntConst)
      | (1ULL << SysYParser::FloatConst))) != 0)) {
      setState(209);
      funcBlockItem();
      setState(214);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(215);
    match(SysYParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncBlockItemContext ------------------------------------------------------------------

SysYParser::FuncBlockItemContext::FuncBlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::DeclContext* SysYParser::FuncBlockItemContext::decl() {
  return getRuleContext<SysYParser::DeclContext>(0);
}

SysYParser::StmtContext* SysYParser::FuncBlockItemContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}


size_t SysYParser::FuncBlockItemContext::getRuleIndex() const {
  return SysYParser::RuleFuncBlockItem;
}

void SysYParser::FuncBlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncBlockItem(this);
}

void SysYParser::FuncBlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncBlockItem(this);
}

SysYParser::FuncBlockItemContext* SysYParser::funcBlockItem() {
  FuncBlockItemContext *_localctx = _tracker.createInstance<FuncBlockItemContext>(_ctx, getState());
  enterRule(_localctx, 30, SysYParser::RuleFuncBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(219);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__0:
      case SysYParser::T__3:
      case SysYParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(217);
        decl();
        break;
      }

      case SysYParser::T__2:
      case SysYParser::T__8:
      case SysYParser::T__10:
      case SysYParser::T__13:
      case SysYParser::T__15:
      case SysYParser::T__16:
      case SysYParser::T__19:
      case SysYParser::T__20:
      case SysYParser::T__21:
      case SysYParser::Ident:
      case SysYParser::IntConst:
      case SysYParser::FloatConst: {
        enterOuterAlt(_localctx, 2);
        setState(218);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

SysYParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::StmtContext::getRuleIndex() const {
  return SysYParser::RuleStmt;
}

void SysYParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->hasReturn = ctx->hasReturn;
  this->returnType = ctx->returnType;
  this->codes = ctx->codes;
  this->beginArray = ctx->beginArray;
  this->docLVal = ctx->docLVal;
  this->lValDoc = ctx->lValDoc;
}

//----------------- StmtBlockContext ------------------------------------------------------------------

SysYParser::FuncBlockContext* SysYParser::StmtBlockContext::funcBlock() {
  return getRuleContext<SysYParser::FuncBlockContext>(0);
}

SysYParser::StmtBlockContext::StmtBlockContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::StmtBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtBlock(this);
}
void SysYParser::StmtBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtBlock(this);
}
//----------------- StmtExpressionContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::StmtExpressionContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::StmtExpressionContext::StmtExpressionContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::StmtExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtExpression(this);
}
void SysYParser::StmtExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtExpression(this);
}
//----------------- StmtAssignmentContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::StmtAssignmentContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::ExpContext* SysYParser::StmtAssignmentContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::StmtAssignmentContext::StmtAssignmentContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::StmtAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtAssignment(this);
}
void SysYParser::StmtAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtAssignment(this);
}
//----------------- StmtCtrlSeqContext ------------------------------------------------------------------

SysYParser::CondContext* SysYParser::StmtCtrlSeqContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

std::vector<SysYParser::StmtContext *> SysYParser::StmtCtrlSeqContext::stmt() {
  return getRuleContexts<SysYParser::StmtContext>();
}

SysYParser::StmtContext* SysYParser::StmtCtrlSeqContext::stmt(size_t i) {
  return getRuleContext<SysYParser::StmtContext>(i);
}

SysYParser::SubStmtContext* SysYParser::StmtCtrlSeqContext::subStmt() {
  return getRuleContext<SysYParser::SubStmtContext>(0);
}

SysYParser::StmtCtrlSeqContext::StmtCtrlSeqContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::StmtCtrlSeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtCtrlSeq(this);
}
void SysYParser::StmtCtrlSeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtCtrlSeq(this);
}
//----------------- StmtReturnContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::StmtReturnContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::StmtReturnContext::StmtReturnContext(StmtContext *ctx) { copyFrom(ctx); }

void SysYParser::StmtReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmtReturn(this);
}
void SysYParser::StmtReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmtReturn(this);
}
SysYParser::StmtContext* SysYParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 32, SysYParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(251);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(221);
      lVal();
      setState(222);
      match(SysYParser::T__7);
      setState(223);
      exp();
      setState(224);
      match(SysYParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(227);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__10)
        | (1ULL << SysYParser::T__19)
        | (1ULL << SysYParser::T__20)
        | (1ULL << SysYParser::T__21)
        | (1ULL << SysYParser::Ident)
        | (1ULL << SysYParser::IntConst)
        | (1ULL << SysYParser::FloatConst))) != 0)) {
        setState(226);
        exp();
      }
      setState(229);
      match(SysYParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(230);
      funcBlock();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(231);
      match(SysYParser::T__13);
      setState(232);
      match(SysYParser::T__10);
      setState(233);
      cond();
      setState(234);
      match(SysYParser::T__11);
      setState(235);
      stmt();
      setState(238);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(236);
        match(SysYParser::T__14);
        setState(237);
        stmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(240);
      match(SysYParser::T__15);
      setState(241);
      match(SysYParser::T__10);
      setState(242);
      cond();
      setState(243);
      match(SysYParser::T__11);
      setState(244);
      subStmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::StmtReturnContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(246);
      match(SysYParser::T__16);
      setState(248);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__10)
        | (1ULL << SysYParser::T__19)
        | (1ULL << SysYParser::T__20)
        | (1ULL << SysYParser::T__21)
        | (1ULL << SysYParser::Ident)
        | (1ULL << SysYParser::IntConst)
        | (1ULL << SysYParser::FloatConst))) != 0)) {
        setState(247);
        exp();
      }
      setState(250);
      match(SysYParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

SysYParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::BlockItemContext *> SysYParser::BlockContext::blockItem() {
  return getRuleContexts<SysYParser::BlockItemContext>();
}

SysYParser::BlockItemContext* SysYParser::BlockContext::blockItem(size_t i) {
  return getRuleContext<SysYParser::BlockItemContext>(i);
}


size_t SysYParser::BlockContext::getRuleIndex() const {
  return SysYParser::RuleBlock;
}

void SysYParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void SysYParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

SysYParser::BlockContext* SysYParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 34, SysYParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(SysYParser::T__8);
    setState(257);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__0)
      | (1ULL << SysYParser::T__2)
      | (1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__4)
      | (1ULL << SysYParser::T__8)
      | (1ULL << SysYParser::T__10)
      | (1ULL << SysYParser::T__13)
      | (1ULL << SysYParser::T__15)
      | (1ULL << SysYParser::T__16)
      | (1ULL << SysYParser::T__17)
      | (1ULL << SysYParser::T__18)
      | (1ULL << SysYParser::T__19)
      | (1ULL << SysYParser::T__20)
      | (1ULL << SysYParser::T__21)
      | (1ULL << SysYParser::Ident)
      | (1ULL << SysYParser::IntConst)
      | (1ULL << SysYParser::FloatConst))) != 0)) {
      setState(254);
      blockItem();
      setState(259);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(260);
    match(SysYParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

SysYParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::DeclContext* SysYParser::BlockItemContext::decl() {
  return getRuleContext<SysYParser::DeclContext>(0);
}

SysYParser::SubStmtContext* SysYParser::BlockItemContext::subStmt() {
  return getRuleContext<SysYParser::SubStmtContext>(0);
}


size_t SysYParser::BlockItemContext::getRuleIndex() const {
  return SysYParser::RuleBlockItem;
}

void SysYParser::BlockItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockItem(this);
}

void SysYParser::BlockItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockItem(this);
}

SysYParser::BlockItemContext* SysYParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 36, SysYParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(264);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__0:
      case SysYParser::T__3:
      case SysYParser::T__4: {
        enterOuterAlt(_localctx, 1);
        setState(262);
        decl();
        break;
      }

      case SysYParser::T__2:
      case SysYParser::T__8:
      case SysYParser::T__10:
      case SysYParser::T__13:
      case SysYParser::T__15:
      case SysYParser::T__16:
      case SysYParser::T__17:
      case SysYParser::T__18:
      case SysYParser::T__19:
      case SysYParser::T__20:
      case SysYParser::T__21:
      case SysYParser::Ident:
      case SysYParser::IntConst:
      case SysYParser::FloatConst: {
        enterOuterAlt(_localctx, 2);
        setState(263);
        subStmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubStmtContext ------------------------------------------------------------------

SysYParser::SubStmtContext::SubStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::SubStmtContext::getRuleIndex() const {
  return SysYParser::RuleSubStmt;
}

void SysYParser::SubStmtContext::copyFrom(SubStmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->hasReturn = ctx->hasReturn;
  this->returnType = ctx->returnType;
  this->codes = ctx->codes;
  this->beginArray = ctx->beginArray;
  this->docLVal = ctx->docLVal;
  this->lValDoc = ctx->lValDoc;
}

//----------------- SubStmtExpressionContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::SubStmtExpressionContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::SubStmtExpressionContext::SubStmtExpressionContext(SubStmtContext *ctx) { copyFrom(ctx); }

void SysYParser::SubStmtExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStmtExpression(this);
}
void SysYParser::SubStmtExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStmtExpression(this);
}
//----------------- SubStmtBlockContext ------------------------------------------------------------------

SysYParser::BlockContext* SysYParser::SubStmtBlockContext::block() {
  return getRuleContext<SysYParser::BlockContext>(0);
}

SysYParser::SubStmtBlockContext::SubStmtBlockContext(SubStmtContext *ctx) { copyFrom(ctx); }

void SysYParser::SubStmtBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStmtBlock(this);
}
void SysYParser::SubStmtBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStmtBlock(this);
}
//----------------- SubStmtAssignmentContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::SubStmtAssignmentContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::ExpContext* SysYParser::SubStmtAssignmentContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::SubStmtAssignmentContext::SubStmtAssignmentContext(SubStmtContext *ctx) { copyFrom(ctx); }

void SysYParser::SubStmtAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStmtAssignment(this);
}
void SysYParser::SubStmtAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStmtAssignment(this);
}
//----------------- SubStmtCtrlSeqContext ------------------------------------------------------------------

SysYParser::CondContext* SysYParser::SubStmtCtrlSeqContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

std::vector<SysYParser::SubStmtContext *> SysYParser::SubStmtCtrlSeqContext::subStmt() {
  return getRuleContexts<SysYParser::SubStmtContext>();
}

SysYParser::SubStmtContext* SysYParser::SubStmtCtrlSeqContext::subStmt(size_t i) {
  return getRuleContext<SysYParser::SubStmtContext>(i);
}

SysYParser::SubStmtCtrlSeqContext::SubStmtCtrlSeqContext(SubStmtContext *ctx) { copyFrom(ctx); }

void SysYParser::SubStmtCtrlSeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStmtCtrlSeq(this);
}
void SysYParser::SubStmtCtrlSeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStmtCtrlSeq(this);
}
//----------------- SubStmtReturnContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::SubStmtReturnContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::SubStmtReturnContext::SubStmtReturnContext(SubStmtContext *ctx) { copyFrom(ctx); }

void SysYParser::SubStmtReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubStmtReturn(this);
}
void SysYParser::SubStmtReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubStmtReturn(this);
}
SysYParser::SubStmtContext* SysYParser::subStmt() {
  SubStmtContext *_localctx = _tracker.createInstance<SubStmtContext>(_ctx, getState());
  enterRule(_localctx, 38, SysYParser::RuleSubStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(300);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtAssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(266);
      lVal();
      setState(267);
      match(SysYParser::T__7);
      setState(268);
      exp();
      setState(269);
      match(SysYParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtExpressionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(272);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__10)
        | (1ULL << SysYParser::T__19)
        | (1ULL << SysYParser::T__20)
        | (1ULL << SysYParser::T__21)
        | (1ULL << SysYParser::Ident)
        | (1ULL << SysYParser::IntConst)
        | (1ULL << SysYParser::FloatConst))) != 0)) {
        setState(271);
        exp();
      }
      setState(274);
      match(SysYParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtBlockContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(275);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(276);
      match(SysYParser::T__13);
      setState(277);
      match(SysYParser::T__10);
      setState(278);
      cond();
      setState(279);
      match(SysYParser::T__11);
      setState(280);
      subStmt();
      setState(283);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
      case 1: {
        setState(281);
        match(SysYParser::T__14);
        setState(282);
        subStmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(285);
      match(SysYParser::T__15);
      setState(286);
      match(SysYParser::T__10);
      setState(287);
      cond();
      setState(288);
      match(SysYParser::T__11);
      setState(289);
      subStmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(291);
      match(SysYParser::T__17);
      setState(292);
      match(SysYParser::T__2);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtCtrlSeqContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(293);
      match(SysYParser::T__18);
      setState(294);
      match(SysYParser::T__2);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<SubStmtContext *>(_tracker.createInstance<SysYParser::SubStmtReturnContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(295);
      match(SysYParser::T__16);
      setState(297);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__10)
        | (1ULL << SysYParser::T__19)
        | (1ULL << SysYParser::T__20)
        | (1ULL << SysYParser::T__21)
        | (1ULL << SysYParser::Ident)
        | (1ULL << SysYParser::IntConst)
        | (1ULL << SysYParser::FloatConst))) != 0)) {
        setState(296);
        exp();
      }
      setState(299);
      match(SysYParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

SysYParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::AddExpContext* SysYParser::ExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}


size_t SysYParser::ExpContext::getRuleIndex() const {
  return SysYParser::RuleExp;
}

void SysYParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void SysYParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}

SysYParser::ExpContext* SysYParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 40, SysYParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    addExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

SysYParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::LOrExpContext* SysYParser::CondContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}


size_t SysYParser::CondContext::getRuleIndex() const {
  return SysYParser::RuleCond;
}

void SysYParser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void SysYParser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}

SysYParser::CondContext* SysYParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 42, SysYParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    lOrExp(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

SysYParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::LValContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

std::vector<SysYParser::ExpContext *> SysYParser::LValContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::LValContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}


size_t SysYParser::LValContext::getRuleIndex() const {
  return SysYParser::RuleLVal;
}

void SysYParser::LValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLVal(this);
}

void SysYParser::LValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLVal(this);
}

SysYParser::LValContext* SysYParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 44, SysYParser::RuleLVal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(SysYParser::Ident);
    setState(313);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(307);
        match(SysYParser::T__5);
        setState(308);
        exp();
        setState(309);
        match(SysYParser::T__6); 
      }
      setState(315);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

SysYParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::PrimaryExpContext::getRuleIndex() const {
  return SysYParser::RulePrimaryExp;
}

void SysYParser::PrimaryExpContext::copyFrom(PrimaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->shape = ctx->shape;
  this->metaDataType = ctx->metaDataType;
  this->operand = ctx->operand;
  this->indexOperand = ctx->indexOperand;
}

//----------------- PrimaryExpNestExpContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::PrimaryExpNestExpContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::PrimaryExpNestExpContext::PrimaryExpNestExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void SysYParser::PrimaryExpNestExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpNestExp(this);
}
void SysYParser::PrimaryExpNestExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpNestExp(this);
}
//----------------- PrimaryExpNumberContext ------------------------------------------------------------------

SysYParser::NumberContext* SysYParser::PrimaryExpNumberContext::number() {
  return getRuleContext<SysYParser::NumberContext>(0);
}

SysYParser::PrimaryExpNumberContext::PrimaryExpNumberContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void SysYParser::PrimaryExpNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpNumber(this);
}
void SysYParser::PrimaryExpNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpNumber(this);
}
//----------------- PrimaryExplValContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::PrimaryExplValContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::PrimaryExplValContext::PrimaryExplValContext(PrimaryExpContext *ctx) { copyFrom(ctx); }

void SysYParser::PrimaryExplValContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExplVal(this);
}
void SysYParser::PrimaryExplValContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExplVal(this);
}
SysYParser::PrimaryExpContext* SysYParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 46, SysYParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(322);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__10: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<SysYParser::PrimaryExpNestExpContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(316);
        match(SysYParser::T__10);
        setState(317);
        exp();
        setState(318);
        match(SysYParser::T__11);
        break;
      }

      case SysYParser::Ident: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<SysYParser::PrimaryExplValContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(320);
        lVal();
        break;
      }

      case SysYParser::IntConst:
      case SysYParser::FloatConst: {
        _localctx = dynamic_cast<PrimaryExpContext *>(_tracker.createInstance<SysYParser::PrimaryExpNumberContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(321);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

SysYParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::UnaryExpContext::getRuleIndex() const {
  return SysYParser::RuleUnaryExp;
}

void SysYParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->shape = ctx->shape;
  this->metaDataType = ctx->metaDataType;
  this->operand = ctx->operand;
  this->indexOperand = ctx->indexOperand;
}

//----------------- UnaryExpFuncContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::UnaryExpFuncContext::Ident() {
  return getToken(SysYParser::Ident, 0);
}

SysYParser::FuncRParamsContext* SysYParser::UnaryExpFuncContext::funcRParams() {
  return getRuleContext<SysYParser::FuncRParamsContext>(0);
}

SysYParser::UnaryExpFuncContext::UnaryExpFuncContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void SysYParser::UnaryExpFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpFunc(this);
}
void SysYParser::UnaryExpFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpFunc(this);
}
//----------------- UnaryExpPrimaryExpContext ------------------------------------------------------------------

SysYParser::PrimaryExpContext* SysYParser::UnaryExpPrimaryExpContext::primaryExp() {
  return getRuleContext<SysYParser::PrimaryExpContext>(0);
}

SysYParser::UnaryExpPrimaryExpContext::UnaryExpPrimaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void SysYParser::UnaryExpPrimaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpPrimaryExp(this);
}
void SysYParser::UnaryExpPrimaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpPrimaryExp(this);
}
//----------------- UnaryExpNestUnaryExpContext ------------------------------------------------------------------

SysYParser::UnaryOpContext* SysYParser::UnaryExpNestUnaryExpContext::unaryOp() {
  return getRuleContext<SysYParser::UnaryOpContext>(0);
}

SysYParser::UnaryExpContext* SysYParser::UnaryExpNestUnaryExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::UnaryExpNestUnaryExpContext::UnaryExpNestUnaryExpContext(UnaryExpContext *ctx) { copyFrom(ctx); }

void SysYParser::UnaryExpNestUnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpNestUnaryExp(this);
}
void SysYParser::UnaryExpNestUnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpNestUnaryExp(this);
}
SysYParser::UnaryExpContext* SysYParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 48, SysYParser::RuleUnaryExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(334);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<SysYParser::UnaryExpPrimaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(324);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<SysYParser::UnaryExpFuncContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(325);
      match(SysYParser::Ident);
      setState(326);
      match(SysYParser::T__10);
      setState(328);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__10)
        | (1ULL << SysYParser::T__19)
        | (1ULL << SysYParser::T__20)
        | (1ULL << SysYParser::T__21)
        | (1ULL << SysYParser::Ident)
        | (1ULL << SysYParser::IntConst)
        | (1ULL << SysYParser::FloatConst))) != 0)) {
        setState(327);
        funcRParams();
      }
      setState(330);
      match(SysYParser::T__11);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<SysYParser::UnaryExpNestUnaryExpContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(331);
      unaryOp();
      setState(332);
      unaryExp();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

SysYParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::UnaryOpContext::getRuleIndex() const {
  return SysYParser::RuleUnaryOp;
}

void SysYParser::UnaryOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOp(this);
}

void SysYParser::UnaryOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOp(this);
}

SysYParser::UnaryOpContext* SysYParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 50, SysYParser::RuleUnaryOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__19)
      | (1ULL << SysYParser::T__20)
      | (1ULL << SysYParser::T__21))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

SysYParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::ExpContext *> SysYParser::FuncRParamsContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}


size_t SysYParser::FuncRParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncRParams;
}

void SysYParser::FuncRParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncRParams(this);
}

void SysYParser::FuncRParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncRParams(this);
}

SysYParser::FuncRParamsContext* SysYParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 52, SysYParser::RuleFuncRParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    exp();
    setState(343);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(339);
      match(SysYParser::T__1);
      setState(340);
      exp();
      setState(345);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

SysYParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::MulExpContext::getRuleIndex() const {
  return SysYParser::RuleMulExp;
}

void SysYParser::MulExpContext::copyFrom(MulExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->shape = ctx->shape;
  this->metaDataType = ctx->metaDataType;
  this->operand = ctx->operand;
  this->indexOperand = ctx->indexOperand;
}

//----------------- MulExpMulExpContext ------------------------------------------------------------------

SysYParser::MulExpContext* SysYParser::MulExpMulExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::MulOpContext* SysYParser::MulExpMulExpContext::mulOp() {
  return getRuleContext<SysYParser::MulOpContext>(0);
}

SysYParser::UnaryExpContext* SysYParser::MulExpMulExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::MulExpMulExpContext::MulExpMulExpContext(MulExpContext *ctx) { copyFrom(ctx); }

void SysYParser::MulExpMulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpMulExp(this);
}
void SysYParser::MulExpMulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpMulExp(this);
}
//----------------- MulExpUnaryExpContext ------------------------------------------------------------------

SysYParser::UnaryExpContext* SysYParser::MulExpUnaryExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::MulExpUnaryExpContext::MulExpUnaryExpContext(MulExpContext *ctx) { copyFrom(ctx); }

void SysYParser::MulExpUnaryExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulExpUnaryExp(this);
}
void SysYParser::MulExpUnaryExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulExpUnaryExp(this);
}

SysYParser::MulExpContext* SysYParser::mulExp() {
   return mulExp(0);
}

SysYParser::MulExpContext* SysYParser::mulExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, parentState);
  SysYParser::MulExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 54;
  enterRecursionRule(_localctx, 54, SysYParser::RuleMulExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<MulExpUnaryExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(347);
    unaryExp();
    _ctx->stop = _input->LT(-1);
    setState(355);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<MulExpMulExpContext>(_tracker.createInstance<MulExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleMulExp);
        setState(349);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(350);
        mulOp();
        setState(351);
        unaryExp(); 
      }
      setState(357);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

SysYParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::MulOpContext::getRuleIndex() const {
  return SysYParser::RuleMulOp;
}

void SysYParser::MulOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulOp(this);
}

void SysYParser::MulOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulOp(this);
}

SysYParser::MulOpContext* SysYParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 56, SysYParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(358);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__22)
      | (1ULL << SysYParser::T__23)
      | (1ULL << SysYParser::T__24))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

SysYParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::AddExpContext::getRuleIndex() const {
  return SysYParser::RuleAddExp;
}

void SysYParser::AddExpContext::copyFrom(AddExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->isArray = ctx->isArray;
  this->shape = ctx->shape;
  this->metaDataType = ctx->metaDataType;
  this->operand = ctx->operand;
  this->indexOperand = ctx->indexOperand;
}

//----------------- AddExpAddExpContext ------------------------------------------------------------------

SysYParser::AddExpContext* SysYParser::AddExpAddExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::AddOpContext* SysYParser::AddExpAddExpContext::addOp() {
  return getRuleContext<SysYParser::AddOpContext>(0);
}

SysYParser::MulExpContext* SysYParser::AddExpAddExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::AddExpAddExpContext::AddExpAddExpContext(AddExpContext *ctx) { copyFrom(ctx); }

void SysYParser::AddExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpAddExp(this);
}
void SysYParser::AddExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpAddExp(this);
}
//----------------- AddExpMulExpContext ------------------------------------------------------------------

SysYParser::MulExpContext* SysYParser::AddExpMulExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::AddExpMulExpContext::AddExpMulExpContext(AddExpContext *ctx) { copyFrom(ctx); }

void SysYParser::AddExpMulExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpMulExp(this);
}
void SysYParser::AddExpMulExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpMulExp(this);
}

SysYParser::AddExpContext* SysYParser::addExp() {
   return addExp(0);
}

SysYParser::AddExpContext* SysYParser::addExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, parentState);
  SysYParser::AddExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, SysYParser::RuleAddExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<AddExpMulExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(361);
    mulExp(0);
    _ctx->stop = _input->LT(-1);
    setState(369);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<AddExpAddExpContext>(_tracker.createInstance<AddExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleAddExp);
        setState(363);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(364);
        addOp();
        setState(365);
        mulExp(0); 
      }
      setState(371);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

SysYParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::AddOpContext::getRuleIndex() const {
  return SysYParser::RuleAddOp;
}

void SysYParser::AddOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddOp(this);
}

void SysYParser::AddOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddOp(this);
}

SysYParser::AddOpContext* SysYParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 60, SysYParser::RuleAddOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    _la = _input->LA(1);
    if (!(_la == SysYParser::T__19

    || _la == SysYParser::T__20)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

SysYParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::RelExpContext::getRuleIndex() const {
  return SysYParser::RuleRelExp;
}

void SysYParser::RelExpContext::copyFrom(RelExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
  this->operand = ctx->operand;
}

//----------------- RelExpRelExpContext ------------------------------------------------------------------

SysYParser::RelExpContext* SysYParser::RelExpRelExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::RelOpContext* SysYParser::RelExpRelExpContext::relOp() {
  return getRuleContext<SysYParser::RelOpContext>(0);
}

SysYParser::AddExpContext* SysYParser::RelExpRelExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::RelExpRelExpContext::RelExpRelExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void SysYParser::RelExpRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpRelExp(this);
}
void SysYParser::RelExpRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpRelExp(this);
}
//----------------- RelExpAddExpContext ------------------------------------------------------------------

SysYParser::AddExpContext* SysYParser::RelExpAddExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::RelExpAddExpContext::RelExpAddExpContext(RelExpContext *ctx) { copyFrom(ctx); }

void SysYParser::RelExpAddExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpAddExp(this);
}
void SysYParser::RelExpAddExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpAddExp(this);
}

SysYParser::RelExpContext* SysYParser::relExp() {
   return relExp(0);
}

SysYParser::RelExpContext* SysYParser::relExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, parentState);
  SysYParser::RelExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 62;
  enterRecursionRule(_localctx, 62, SysYParser::RuleRelExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<RelExpAddExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(375);
    addExp(0);
    _ctx->stop = _input->LT(-1);
    setState(383);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<RelExpRelExpContext>(_tracker.createInstance<RelExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleRelExp);
        setState(377);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(378);
        relOp();
        setState(379);
        addExp(0); 
      }
      setState(385);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

SysYParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::RelOpContext::getRuleIndex() const {
  return SysYParser::RuleRelOp;
}

void SysYParser::RelOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelOp(this);
}

void SysYParser::RelOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelOp(this);
}

SysYParser::RelOpContext* SysYParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 64, SysYParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__25)
      | (1ULL << SysYParser::T__26)
      | (1ULL << SysYParser::T__27)
      | (1ULL << SysYParser::T__28))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

SysYParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::EqExpContext::getRuleIndex() const {
  return SysYParser::RuleEqExp;
}

void SysYParser::EqExpContext::copyFrom(EqExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
  this->operand = ctx->operand;
}

//----------------- EqExpRelExpContext ------------------------------------------------------------------

SysYParser::RelExpContext* SysYParser::EqExpRelExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::EqExpRelExpContext::EqExpRelExpContext(EqExpContext *ctx) { copyFrom(ctx); }

void SysYParser::EqExpRelExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpRelExp(this);
}
void SysYParser::EqExpRelExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpRelExp(this);
}
//----------------- EqExpEqExpContext ------------------------------------------------------------------

SysYParser::EqExpContext* SysYParser::EqExpEqExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::EqOpContext* SysYParser::EqExpEqExpContext::eqOp() {
  return getRuleContext<SysYParser::EqOpContext>(0);
}

SysYParser::RelExpContext* SysYParser::EqExpEqExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::EqExpEqExpContext::EqExpEqExpContext(EqExpContext *ctx) { copyFrom(ctx); }

void SysYParser::EqExpEqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpEqExp(this);
}
void SysYParser::EqExpEqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpEqExp(this);
}

SysYParser::EqExpContext* SysYParser::eqExp() {
   return eqExp(0);
}

SysYParser::EqExpContext* SysYParser::eqExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, parentState);
  SysYParser::EqExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 66;
  enterRecursionRule(_localctx, 66, SysYParser::RuleEqExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<EqExpRelExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(389);
    relExp(0);
    _ctx->stop = _input->LT(-1);
    setState(397);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<EqExpEqExpContext>(_tracker.createInstance<EqExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleEqExp);
        setState(391);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(392);
        eqOp();
        setState(393);
        relExp(0); 
      }
      setState(399);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqOpContext ------------------------------------------------------------------

SysYParser::EqOpContext::EqOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::EqOpContext::getRuleIndex() const {
  return SysYParser::RuleEqOp;
}

void SysYParser::EqOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqOp(this);
}

void SysYParser::EqOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqOp(this);
}

SysYParser::EqOpContext* SysYParser::eqOp() {
  EqOpContext *_localctx = _tracker.createInstance<EqOpContext>(_ctx, getState());
  enterRule(_localctx, 68, SysYParser::RuleEqOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(400);
    _la = _input->LA(1);
    if (!(_la == SysYParser::T__29

    || _la == SysYParser::T__30)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

SysYParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::LAndExpContext::getRuleIndex() const {
  return SysYParser::RuleLAndExp;
}

void SysYParser::LAndExpContext::copyFrom(LAndExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
  this->operand = ctx->operand;
}

//----------------- LAndExpLAndExpContext ------------------------------------------------------------------

SysYParser::LAndExpContext* SysYParser::LAndExpLAndExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::EqExpContext* SysYParser::LAndExpLAndExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::LAndExpLAndExpContext::LAndExpLAndExpContext(LAndExpContext *ctx) { copyFrom(ctx); }

void SysYParser::LAndExpLAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExpLAndExp(this);
}
void SysYParser::LAndExpLAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExpLAndExp(this);
}
//----------------- LAndExpEqExpContext ------------------------------------------------------------------

SysYParser::EqExpContext* SysYParser::LAndExpEqExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::LAndExpEqExpContext::LAndExpEqExpContext(LAndExpContext *ctx) { copyFrom(ctx); }

void SysYParser::LAndExpEqExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLAndExpEqExp(this);
}
void SysYParser::LAndExpEqExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLAndExpEqExp(this);
}

SysYParser::LAndExpContext* SysYParser::lAndExp() {
   return lAndExp(0);
}

SysYParser::LAndExpContext* SysYParser::lAndExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, parentState);
  SysYParser::LAndExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 70;
  enterRecursionRule(_localctx, 70, SysYParser::RuleLAndExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LAndExpEqExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(403);
    eqExp(0);
    _ctx->stop = _input->LT(-1);
    setState(410);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LAndExpLAndExpContext>(_tracker.createInstance<LAndExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLAndExp);
        setState(405);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");

        setState(406);
        match(SysYParser::T__31);
        setState(407);
        eqExp(0); 
      }
      setState(412);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

SysYParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::LOrExpContext::getRuleIndex() const {
  return SysYParser::RuleLOrExp;
}

void SysYParser::LOrExpContext::copyFrom(LOrExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
  this->operand = ctx->operand;
}

//----------------- LOrExpLAndExpContext ------------------------------------------------------------------

SysYParser::LAndExpContext* SysYParser::LOrExpLAndExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::LOrExpLAndExpContext::LOrExpLAndExpContext(LOrExpContext *ctx) { copyFrom(ctx); }

void SysYParser::LOrExpLAndExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExpLAndExp(this);
}
void SysYParser::LOrExpLAndExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExpLAndExp(this);
}
//----------------- LOrExpLOrExpContext ------------------------------------------------------------------

SysYParser::LOrExpContext* SysYParser::LOrExpLOrExpContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}

SysYParser::LAndExpContext* SysYParser::LOrExpLOrExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::LOrExpLOrExpContext::LOrExpLOrExpContext(LOrExpContext *ctx) { copyFrom(ctx); }

void SysYParser::LOrExpLOrExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLOrExpLOrExp(this);
}
void SysYParser::LOrExpLOrExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLOrExpLOrExp(this);
}

SysYParser::LOrExpContext* SysYParser::lOrExp() {
   return lOrExp(0);
}

SysYParser::LOrExpContext* SysYParser::lOrExp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SysYParser::LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, parentState);
  SysYParser::LOrExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 72;
  enterRecursionRule(_localctx, 72, SysYParser::RuleLOrExp, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<LOrExpLAndExpContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(414);
    lAndExp(0);
    _ctx->stop = _input->LT(-1);
    setState(421);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<LOrExpLOrExpContext>(_tracker.createInstance<LOrExpContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleLOrExp);
        setState(416);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");

        setState(417);
        match(SysYParser::T__32);
        setState(418);
        lAndExp(0); 
      }
      setState(423);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

SysYParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::ConstExpContext::getRuleIndex() const {
  return SysYParser::RuleConstExp;
}

void SysYParser::ConstExpContext::copyFrom(ConstExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
  this->val = ctx->val;
}

//----------------- ConstExpNumberContext ------------------------------------------------------------------

SysYParser::NumberContext* SysYParser::ConstExpNumberContext::number() {
  return getRuleContext<SysYParser::NumberContext>(0);
}

SysYParser::ConstExpNumberContext::ConstExpNumberContext(ConstExpContext *ctx) { copyFrom(ctx); }

void SysYParser::ConstExpNumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpNumber(this);
}
void SysYParser::ConstExpNumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpNumber(this);
}
SysYParser::ConstExpContext* SysYParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 74, SysYParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<ConstExpContext *>(_tracker.createInstance<SysYParser::ConstExpNumberContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(424);
    number();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

SysYParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::NumberContext::getRuleIndex() const {
  return SysYParser::RuleNumber;
}

void SysYParser::NumberContext::copyFrom(NumberContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->metaDataType = ctx->metaDataType;
}

//----------------- NumberFloatConstContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::NumberFloatConstContext::FloatConst() {
  return getToken(SysYParser::FloatConst, 0);
}

SysYParser::NumberFloatConstContext::NumberFloatConstContext(NumberContext *ctx) { copyFrom(ctx); }

void SysYParser::NumberFloatConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberFloatConst(this);
}
void SysYParser::NumberFloatConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberFloatConst(this);
}
//----------------- NumberIntConstContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::NumberIntConstContext::IntConst() {
  return getToken(SysYParser::IntConst, 0);
}

SysYParser::NumberIntConstContext::NumberIntConstContext(NumberContext *ctx) { copyFrom(ctx); }

void SysYParser::NumberIntConstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberIntConst(this);
}
void SysYParser::NumberIntConstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SysYListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberIntConst(this);
}
SysYParser::NumberContext* SysYParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 76, SysYParser::RuleNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(428);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::IntConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<SysYParser::NumberIntConstContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(426);
        match(SysYParser::IntConst);
        break;
      }

      case SysYParser::FloatConst: {
        _localctx = dynamic_cast<NumberContext *>(_tracker.createInstance<SysYParser::NumberFloatConstContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(427);
        match(SysYParser::FloatConst);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SysYParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 27: return mulExpSempred(dynamic_cast<MulExpContext *>(context), predicateIndex);
    case 29: return addExpSempred(dynamic_cast<AddExpContext *>(context), predicateIndex);
    case 31: return relExpSempred(dynamic_cast<RelExpContext *>(context), predicateIndex);
    case 33: return eqExpSempred(dynamic_cast<EqExpContext *>(context), predicateIndex);
    case 35: return lAndExpSempred(dynamic_cast<LAndExpContext *>(context), predicateIndex);
    case 36: return lOrExpSempred(dynamic_cast<LOrExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SysYParser::mulExpSempred(MulExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::addExpSempred(AddExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::relExpSempred(RelExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::eqExpSempred(EqExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::lAndExpSempred(LAndExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool SysYParser::lOrExpSempred(LOrExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SysYParser::_decisionToDFA;
atn::PredictionContextCache SysYParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SysYParser::_atn;
std::vector<uint16_t> SysYParser::_serializedATN;

std::vector<std::string> SysYParser::_ruleNames = {
  "compUnit", "decl", "constDecl", "bType", "constDef", "constInitVal", 
  "varDecl", "varDef", "initVal", "funcDef", "funcType", "funcFParams", 
  "funcFParam", "brackets", "funcBlock", "funcBlockItem", "stmt", "block", 
  "blockItem", "subStmt", "exp", "cond", "lVal", "primaryExp", "unaryExp", 
  "unaryOp", "funcRParams", "mulExp", "mulOp", "addExp", "addOp", "relExp", 
  "relOp", "eqExp", "eqOp", "lAndExp", "lOrExp", "constExp", "number"
};

std::vector<std::string> SysYParser::_literalNames = {
  "", "'const'", "','", "';'", "'int'", "'float'", "'['", "']'", "'='", 
  "'{'", "'}'", "'('", "')'", "'void'", "'if'", "'else'", "'while'", "'return'", 
  "'break'", "'continue'", "'+'", "'-'", "'!'", "'*'", "'/'", "'%'", "'<'", 
  "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", "'||'"
};

std::vector<std::string> SysYParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "Ident", 
  "IntConst", "DigitSequence", "FloatConst", "DoubleConst", "NewLine", "WhiteSpace", 
  "BlockComment", "LineComment"
};

dfa::Vocabulary SysYParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SysYParser::_tokenNames;

SysYParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2c, 0x1b1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x53, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x54, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x5b, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x62, 0xa, 0x4, 
    0xc, 0x4, 0xe, 0x4, 0x65, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x70, 
    0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x73, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x77, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0x7e, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x81, 0xb, 0x7, 0x5, 0x7, 
    0x83, 0xa, 0x7, 0x3, 0x7, 0x5, 0x7, 0x86, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x8c, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x8f, 
    0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x7, 0x9, 0x98, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x9b, 0xb, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x9f, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xa6, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 
    0xa9, 0xb, 0xa, 0x5, 0xa, 0xab, 0xa, 0xa, 0x3, 0xa, 0x5, 0xa, 0xae, 
    0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xb4, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0xbe, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xc1, 0xb, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xc6, 0xa, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xce, 0xa, 
    0xf, 0xc, 0xf, 0xe, 0xf, 0xd1, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x7, 
    0x10, 0xd5, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xd8, 0xb, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xde, 0xa, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xe6, 
    0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xf1, 0xa, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x5, 0x12, 0xfb, 0xa, 0x12, 0x3, 0x12, 0x5, 0x12, 0xfe, 0xa, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x102, 0xa, 0x13, 0xc, 0x13, 
    0xe, 0x13, 0x105, 0xb, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x5, 0x14, 0x10b, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x113, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x5, 0x15, 0x11e, 0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x12c, 0xa, 0x15, 0x3, 0x15, 
    0x5, 0x15, 0x12f, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x13a, 
    0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x13d, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x145, 0xa, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x14b, 0xa, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x151, 0xa, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x158, 
    0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x15b, 0xb, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x164, 
    0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x167, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x7, 0x1f, 0x172, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x175, 0xb, 
    0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x7, 0x21, 0x180, 0xa, 0x21, 0xc, 0x21, 
    0xe, 0x21, 0x183, 0xb, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x18e, 
    0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x191, 0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 
    0x25, 0x19b, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x19e, 0xb, 0x25, 0x3, 
    0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 
    0x1a6, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x1a9, 0xb, 0x26, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1af, 0xa, 0x28, 0x3, 0x28, 
    0x2, 0x8, 0x38, 0x3c, 0x40, 0x44, 0x48, 0x4a, 0x29, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x2, 
    0x9, 0x3, 0x2, 0x6, 0x7, 0x4, 0x2, 0x6, 0x7, 0xf, 0xf, 0x3, 0x2, 0x16, 
    0x18, 0x3, 0x2, 0x19, 0x1b, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x1c, 0x1f, 
    0x3, 0x2, 0x20, 0x21, 0x2, 0x1c0, 0x2, 0x52, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x8, 0x68, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x6a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x87, 0x3, 0x2, 0x2, 0x2, 0x10, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xad, 0x3, 0x2, 0x2, 0x2, 0x14, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x18, 0xba, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xc2, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x22, 0xfd, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xff, 0x3, 0x2, 0x2, 0x2, 0x26, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x130, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x132, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x134, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x144, 0x3, 0x2, 0x2, 0x2, 0x32, 0x150, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x152, 0x3, 0x2, 0x2, 0x2, 0x36, 0x154, 0x3, 0x2, 0x2, 0x2, 0x38, 0x15c, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x168, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x16a, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x176, 0x3, 0x2, 0x2, 0x2, 0x40, 0x178, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x184, 0x3, 0x2, 0x2, 0x2, 0x44, 0x186, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x192, 0x3, 0x2, 0x2, 0x2, 0x48, 0x194, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x1ae, 0x3, 0x2, 0x2, 0x2, 0x50, 0x53, 0x5, 0x4, 0x3, 0x2, 0x51, 0x53, 
    0x5, 0x14, 0xb, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x57, 0x7, 0x2, 0x2, 0x3, 0x57, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x5b, 0x5, 0x6, 0x4, 0x2, 0x59, 0x5b, 0x5, 0xe, 0x8, 0x2, 0x5a, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x3, 0x2, 0x2, 0x5d, 0x5e, 0x5, 
    0x8, 0x5, 0x2, 0x5e, 0x63, 0x5, 0xa, 0x6, 0x2, 0x5f, 0x60, 0x7, 0x4, 
    0x2, 0x2, 0x60, 0x62, 0x5, 0xa, 0x6, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x62, 0x65, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x66, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x7, 0x5, 0x2, 0x2, 0x67, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x9, 0x2, 0x2, 0x2, 0x69, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x6a, 0x71, 0x7, 0x24, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x8, 
    0x2, 0x2, 0x6c, 0x6d, 0x5, 0x4c, 0x27, 0x2, 0x6d, 0x6e, 0x7, 0x9, 0x2, 
    0x2, 0x6e, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6b, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x73, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x76, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0xa, 0x2, 0x2, 0x75, 0x77, 0x5, 
    0xc, 0x7, 0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x77, 0xb, 0x3, 0x2, 0x2, 0x2, 0x78, 0x86, 0x5, 0x4c, 0x27, 
    0x2, 0x79, 0x82, 0x7, 0xb, 0x2, 0x2, 0x7a, 0x7f, 0x5, 0x4c, 0x27, 0x2, 
    0x7b, 0x7c, 0x7, 0x4, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x4c, 0x27, 0x2, 0x7d, 
    0x7b, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0x7a, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x86, 0x7, 0xc, 0x2, 0x2, 0x85, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x79, 0x3, 0x2, 0x2, 0x2, 0x86, 0xd, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x88, 0x5, 0x8, 0x5, 0x2, 0x88, 0x8d, 0x5, 0x10, 0x9, 0x2, 0x89, 0x8a, 
    0x7, 0x4, 0x2, 0x2, 0x8a, 0x8c, 0x5, 0x10, 0x9, 0x2, 0x8b, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x8c, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x90, 0x3, 0x2, 0x2, 
    0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x7, 0x5, 0x2, 0x2, 
    0x91, 0xf, 0x3, 0x2, 0x2, 0x2, 0x92, 0x99, 0x7, 0x24, 0x2, 0x2, 0x93, 
    0x94, 0x7, 0x8, 0x2, 0x2, 0x94, 0x95, 0x5, 0x4c, 0x27, 0x2, 0x95, 0x96, 
    0x7, 0x9, 0x2, 0x2, 0x96, 0x98, 0x3, 0x2, 0x2, 0x2, 0x97, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0xa, 0x2, 0x2, 
    0x9d, 0x9f, 0x5, 0x12, 0xa, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x11, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xae, 
    0x5, 0x2a, 0x16, 0x2, 0xa1, 0xaa, 0x7, 0xb, 0x2, 0x2, 0xa2, 0xa7, 0x5, 
    0x12, 0xa, 0x2, 0xa3, 0xa4, 0x7, 0x4, 0x2, 0x2, 0xa4, 0xa6, 0x5, 0x12, 
    0xa, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa9, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0xa2, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xac, 0xae, 0x7, 0xc, 0x2, 0x2, 0xad, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0xad, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xae, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0xaf, 0xb0, 0x5, 0x16, 0xc, 0x2, 0xb0, 0xb1, 0x7, 0x24, 0x2, 
    0x2, 0xb1, 0xb3, 0x7, 0xd, 0x2, 0x2, 0xb2, 0xb4, 0x5, 0x18, 0xd, 0x2, 
    0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0xe, 0x2, 0x2, 0xb6, 0xb7, 
    0x5, 0x1e, 0x10, 0x2, 0xb7, 0x15, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x9, 
    0x3, 0x2, 0x2, 0xb9, 0x17, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbf, 0x5, 0x1a, 
    0xe, 0x2, 0xbb, 0xbc, 0x7, 0x4, 0x2, 0x2, 0xbc, 0xbe, 0x5, 0x1a, 0xe, 
    0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 
    0x5, 0x8, 0x5, 0x2, 0xc3, 0xc5, 0x7, 0x24, 0x2, 0x2, 0xc4, 0xc6, 0x5, 
    0x1c, 0xf, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0xc6, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x8, 0x2, 
    0x2, 0xc8, 0xcf, 0x7, 0x9, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x8, 0x2, 0x2, 
    0xca, 0xcb, 0x5, 0x2a, 0x16, 0x2, 0xcb, 0xcc, 0x7, 0x9, 0x2, 0x2, 0xcc, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 
    0x2, 0x2, 0xd2, 0xd6, 0x7, 0xb, 0x2, 0x2, 0xd3, 0xd5, 0x5, 0x20, 0x11, 
    0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 0x2, 
    0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 
    0xd9, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 
    0x7, 0xc, 0x2, 0x2, 0xda, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x5, 
    0x4, 0x3, 0x2, 0xdc, 0xde, 0x5, 0x22, 0x12, 0x2, 0xdd, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0xdd, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0xe0, 0x5, 0x2e, 0x18, 0x2, 0xe0, 0xe1, 0x7, 0xa, 0x2, 0x2, 
    0xe1, 0xe2, 0x5, 0x2a, 0x16, 0x2, 0xe2, 0xe3, 0x7, 0x5, 0x2, 0x2, 0xe3, 
    0xfe, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe6, 0x5, 0x2a, 0x16, 0x2, 0xe5, 0xe4, 
    0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 
    0x2, 0x2, 0x2, 0xe7, 0xfe, 0x7, 0x5, 0x2, 0x2, 0xe8, 0xfe, 0x5, 0x1e, 
    0x10, 0x2, 0xe9, 0xea, 0x7, 0x10, 0x2, 0x2, 0xea, 0xeb, 0x7, 0xd, 0x2, 
    0x2, 0xeb, 0xec, 0x5, 0x2c, 0x17, 0x2, 0xec, 0xed, 0x7, 0xe, 0x2, 0x2, 
    0xed, 0xf0, 0x5, 0x22, 0x12, 0x2, 0xee, 0xef, 0x7, 0x11, 0x2, 0x2, 0xef, 
    0xf1, 0x5, 0x22, 0x12, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x7, 
    0x12, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0xd, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x2c, 
    0x17, 0x2, 0xf5, 0xf6, 0x7, 0xe, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x28, 0x15, 
    0x2, 0xf7, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xfa, 0x7, 0x13, 0x2, 0x2, 
    0xf9, 0xfb, 0x5, 0x2a, 0x16, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfe, 
    0x7, 0x5, 0x2, 0x2, 0xfd, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xe5, 0x3, 
    0x2, 0x2, 0x2, 0xfd, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xe9, 0x3, 0x2, 
    0x2, 0x2, 0xfd, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xfe, 0x23, 0x3, 0x2, 0x2, 0x2, 0xff, 0x103, 0x7, 0xb, 0x2, 0x2, 
    0x100, 0x102, 0x5, 0x26, 0x14, 0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 0x2, 
    0x102, 0x105, 0x3, 0x2, 0x2, 0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 
    0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 0x104, 0x106, 0x3, 0x2, 0x2, 0x2, 
    0x105, 0x103, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x7, 0xc, 0x2, 0x2, 
    0x107, 0x25, 0x3, 0x2, 0x2, 0x2, 0x108, 0x10b, 0x5, 0x4, 0x3, 0x2, 0x109, 
    0x10b, 0x5, 0x28, 0x15, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10a, 
    0x109, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x27, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 
    0x5, 0x2e, 0x18, 0x2, 0x10d, 0x10e, 0x7, 0xa, 0x2, 0x2, 0x10e, 0x10f, 
    0x5, 0x2a, 0x16, 0x2, 0x10f, 0x110, 0x7, 0x5, 0x2, 0x2, 0x110, 0x12f, 
    0x3, 0x2, 0x2, 0x2, 0x111, 0x113, 0x5, 0x2a, 0x16, 0x2, 0x112, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 
    0x3, 0x2, 0x2, 0x2, 0x114, 0x12f, 0x7, 0x5, 0x2, 0x2, 0x115, 0x12f, 
    0x5, 0x24, 0x13, 0x2, 0x116, 0x117, 0x7, 0x10, 0x2, 0x2, 0x117, 0x118, 
    0x7, 0xd, 0x2, 0x2, 0x118, 0x119, 0x5, 0x2c, 0x17, 0x2, 0x119, 0x11a, 
    0x7, 0xe, 0x2, 0x2, 0x11a, 0x11d, 0x5, 0x28, 0x15, 0x2, 0x11b, 0x11c, 
    0x7, 0x11, 0x2, 0x2, 0x11c, 0x11e, 0x5, 0x28, 0x15, 0x2, 0x11d, 0x11b, 
    0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x12f, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x7, 0x12, 0x2, 0x2, 0x120, 0x121, 
    0x7, 0xd, 0x2, 0x2, 0x121, 0x122, 0x5, 0x2c, 0x17, 0x2, 0x122, 0x123, 
    0x7, 0xe, 0x2, 0x2, 0x123, 0x124, 0x5, 0x28, 0x15, 0x2, 0x124, 0x12f, 
    0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x7, 0x14, 0x2, 0x2, 0x126, 0x12f, 
    0x7, 0x5, 0x2, 0x2, 0x127, 0x128, 0x7, 0x15, 0x2, 0x2, 0x128, 0x12f, 
    0x7, 0x5, 0x2, 0x2, 0x129, 0x12b, 0x7, 0x13, 0x2, 0x2, 0x12a, 0x12c, 
    0x5, 0x2a, 0x16, 0x2, 0x12b, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 
    0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12f, 
    0x7, 0x5, 0x2, 0x2, 0x12e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x12e, 0x115, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x116, 
    0x3, 0x2, 0x2, 0x2, 0x12e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x125, 
    0x3, 0x2, 0x2, 0x2, 0x12e, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x129, 
    0x3, 0x2, 0x2, 0x2, 0x12f, 0x29, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x5, 
    0x3c, 0x1f, 0x2, 0x131, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x5, 
    0x4a, 0x26, 0x2, 0x133, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x134, 0x13b, 0x7, 
    0x24, 0x2, 0x2, 0x135, 0x136, 0x7, 0x8, 0x2, 0x2, 0x136, 0x137, 0x5, 
    0x2a, 0x16, 0x2, 0x137, 0x138, 0x7, 0x9, 0x2, 0x2, 0x138, 0x13a, 0x3, 
    0x2, 0x2, 0x2, 0x139, 0x135, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13d, 0x3, 
    0x2, 0x2, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x3, 
    0x2, 0x2, 0x2, 0x13c, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13b, 0x3, 0x2, 
    0x2, 0x2, 0x13e, 0x13f, 0x7, 0xd, 0x2, 0x2, 0x13f, 0x140, 0x5, 0x2a, 
    0x16, 0x2, 0x140, 0x141, 0x7, 0xe, 0x2, 0x2, 0x141, 0x145, 0x3, 0x2, 
    0x2, 0x2, 0x142, 0x145, 0x5, 0x2e, 0x18, 0x2, 0x143, 0x145, 0x5, 0x4e, 
    0x28, 0x2, 0x144, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 0x2, 
    0x2, 0x2, 0x144, 0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x146, 0x151, 0x5, 0x30, 0x19, 0x2, 0x147, 0x148, 0x7, 0x24, 0x2, 
    0x2, 0x148, 0x14a, 0x7, 0xd, 0x2, 0x2, 0x149, 0x14b, 0x5, 0x36, 0x1c, 
    0x2, 0x14a, 0x149, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x151, 0x7, 0xe, 0x2, 
    0x2, 0x14d, 0x14e, 0x5, 0x34, 0x1b, 0x2, 0x14e, 0x14f, 0x5, 0x32, 0x1a, 
    0x2, 0x14f, 0x151, 0x3, 0x2, 0x2, 0x2, 0x150, 0x146, 0x3, 0x2, 0x2, 
    0x2, 0x150, 0x147, 0x3, 0x2, 0x2, 0x2, 0x150, 0x14d, 0x3, 0x2, 0x2, 
    0x2, 0x151, 0x33, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x9, 0x4, 0x2, 0x2, 
    0x153, 0x35, 0x3, 0x2, 0x2, 0x2, 0x154, 0x159, 0x5, 0x2a, 0x16, 0x2, 
    0x155, 0x156, 0x7, 0x4, 0x2, 0x2, 0x156, 0x158, 0x5, 0x2a, 0x16, 0x2, 
    0x157, 0x155, 0x3, 0x2, 0x2, 0x2, 0x158, 0x15b, 0x3, 0x2, 0x2, 0x2, 
    0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15a, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x37, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15c, 
    0x15d, 0x8, 0x1d, 0x1, 0x2, 0x15d, 0x15e, 0x5, 0x32, 0x1a, 0x2, 0x15e, 
    0x165, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0xc, 0x3, 0x2, 0x2, 0x160, 
    0x161, 0x5, 0x3a, 0x1e, 0x2, 0x161, 0x162, 0x5, 0x32, 0x1a, 0x2, 0x162, 
    0x164, 0x3, 0x2, 0x2, 0x2, 0x163, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x164, 
    0x167, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x165, 
    0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x39, 0x3, 0x2, 0x2, 0x2, 0x167, 0x165, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x9, 0x5, 0x2, 0x2, 0x169, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x16a, 0x16b, 0x8, 0x1f, 0x1, 0x2, 0x16b, 0x16c, 0x5, 
    0x38, 0x1d, 0x2, 0x16c, 0x173, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0xc, 
    0x3, 0x2, 0x2, 0x16e, 0x16f, 0x5, 0x3e, 0x20, 0x2, 0x16f, 0x170, 0x5, 
    0x38, 0x1d, 0x2, 0x170, 0x172, 0x3, 0x2, 0x2, 0x2, 0x171, 0x16d, 0x3, 
    0x2, 0x2, 0x2, 0x172, 0x175, 0x3, 0x2, 0x2, 0x2, 0x173, 0x171, 0x3, 
    0x2, 0x2, 0x2, 0x173, 0x174, 0x3, 0x2, 0x2, 0x2, 0x174, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x175, 0x173, 0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x9, 0x6, 
    0x2, 0x2, 0x177, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x8, 0x21, 
    0x1, 0x2, 0x179, 0x17a, 0x5, 0x3c, 0x1f, 0x2, 0x17a, 0x181, 0x3, 0x2, 
    0x2, 0x2, 0x17b, 0x17c, 0xc, 0x3, 0x2, 0x2, 0x17c, 0x17d, 0x5, 0x42, 
    0x22, 0x2, 0x17d, 0x17e, 0x5, 0x3c, 0x1f, 0x2, 0x17e, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x17f, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x180, 0x183, 0x3, 0x2, 
    0x2, 0x2, 0x181, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 0x3, 0x2, 
    0x2, 0x2, 0x182, 0x41, 0x3, 0x2, 0x2, 0x2, 0x183, 0x181, 0x3, 0x2, 0x2, 
    0x2, 0x184, 0x185, 0x9, 0x7, 0x2, 0x2, 0x185, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x186, 0x187, 0x8, 0x23, 0x1, 0x2, 0x187, 0x188, 0x5, 0x40, 0x21, 0x2, 
    0x188, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0xc, 0x3, 0x2, 0x2, 
    0x18a, 0x18b, 0x5, 0x46, 0x24, 0x2, 0x18b, 0x18c, 0x5, 0x40, 0x21, 0x2, 
    0x18c, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x189, 0x3, 0x2, 0x2, 0x2, 
    0x18e, 0x191, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x18d, 0x3, 0x2, 0x2, 0x2, 
    0x18f, 0x190, 0x3, 0x2, 0x2, 0x2, 0x190, 0x45, 0x3, 0x2, 0x2, 0x2, 0x191, 
    0x18f, 0x3, 0x2, 0x2, 0x2, 0x192, 0x193, 0x9, 0x8, 0x2, 0x2, 0x193, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 0x8, 0x25, 0x1, 0x2, 0x195, 
    0x196, 0x5, 0x44, 0x23, 0x2, 0x196, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x197, 
    0x198, 0xc, 0x3, 0x2, 0x2, 0x198, 0x199, 0x7, 0x22, 0x2, 0x2, 0x199, 
    0x19b, 0x5, 0x44, 0x23, 0x2, 0x19a, 0x197, 0x3, 0x2, 0x2, 0x2, 0x19b, 
    0x19e, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19c, 
    0x19d, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x49, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19c, 
    0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x8, 0x26, 0x1, 0x2, 0x1a0, 0x1a1, 
    0x5, 0x48, 0x25, 0x2, 0x1a1, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 
    0xc, 0x3, 0x2, 0x2, 0x1a3, 0x1a4, 0x7, 0x23, 0x2, 0x2, 0x1a4, 0x1a6, 
    0x5, 0x48, 0x25, 0x2, 0x1a5, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a9, 
    0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 
    0x3, 0x2, 0x2, 0x2, 0x1a8, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x5, 0x4e, 0x28, 0x2, 0x1ab, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x1ac, 0x1af, 0x7, 0x25, 0x2, 0x2, 0x1ad, 0x1af, 0x7, 
    0x27, 0x2, 0x2, 0x1ae, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1ad, 0x3, 
    0x2, 0x2, 0x2, 0x1af, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x52, 0x54, 0x5a, 
    0x63, 0x71, 0x76, 0x7f, 0x82, 0x85, 0x8d, 0x99, 0x9e, 0xa7, 0xaa, 0xad, 
    0xb3, 0xbf, 0xc5, 0xcf, 0xd6, 0xdd, 0xe5, 0xf0, 0xfa, 0xfd, 0x103, 0x10a, 
    0x112, 0x11d, 0x12b, 0x12e, 0x13b, 0x144, 0x14a, 0x150, 0x159, 0x165, 
    0x173, 0x181, 0x18f, 0x19c, 0x1a7, 0x1ae, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SysYParser::Initializer SysYParser::_init;
