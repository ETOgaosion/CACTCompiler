#include "IROperands.h"

#include <utility>

using namespace std;

IRLabel::IRLabel(string newName) : IROperand(OperandType::LABEL) {
    labelName = std::move(newName);
}

IRValue::IRValue(MetaDataType newMetaDataType, const std::string& inValue) : IROperand(OperandType::VALUE) {
    metaDataType = newMetaDataType;
    value.assign(inValue);
}

void IRValue::addValue(const string& newValue) {
    value.assign(newValue);
}

string IRValue::getValue() const {
    return value;
}

IRSymbolVariable::IRSymbolVariable(AbstractSymbol *newSymbol) : IROperand(OperandType::SYMBOLVAR) {
    symbol = newSymbol;
}

void IRSymbolVariable::setMemOffset(int offset) {}

int IRSymbolVariable::getMemOffset() const {}

IRTempVariable::IRTempVariable(string newName, MetaDataType newMetaDataType) : IROperand(OperandType::TEMPVAR) {
    symbolName = std::move(newName);
    metaDataType = newMetaDataType;
}

void IRTempVariable::setMemOffset(int offset) {}

int IRTempVariable::getMemOffset() const {}