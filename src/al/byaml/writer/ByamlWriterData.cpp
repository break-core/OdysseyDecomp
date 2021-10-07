#include "al/byaml/writer/ByamlWriterData.h"

#include <stream/seadStream.h>
#include "al/byaml/writer/ByamlWriterBigDataList.h"

namespace al {

u32 ByamlWriterData::calcPackSize() const {return 4;}
u8 ByamlWriterData::getTypeCode() const {return 0;}
bool ByamlWriterData::isContainer() const {return false;}
void ByamlWriterData::makeIndex() {}
void ByamlWriterData::print(int) const {}
void ByamlWriterData::printIndent(int) const {}
ByamlWriterData::~ByamlWriterData() {}

ByamlWriterBool::ByamlWriterBool(bool value) : mValue(value) {}
u8 ByamlWriterBool::getTypeCode() const {return 0xD0;}
void ByamlWriterBool::print(int) const {}
void ByamlWriterBool::write(sead::WriteStream* stream) const {stream->writeU32(mValue);}

ByamlWriterInt::ByamlWriterInt(int value) : mValue(value) {}
u8 ByamlWriterInt::getTypeCode() const {return 0xD1;}
void ByamlWriterInt::print(int) const {}
void ByamlWriterInt::write(sead::WriteStream* stream) const {stream->writeS32(mValue);}

ByamlWriterFloat::ByamlWriterFloat(float value) : mValue(value) {}
u8 ByamlWriterFloat::getTypeCode() const {return 0xD2;}
void ByamlWriterFloat::print(int) const {}
void ByamlWriterFloat::write(sead::WriteStream* stream) const {stream->writeF32(mValue);}



ByamlWriterBigData::ByamlWriterBigData(al::ByamlWriterBigDataList* list) : mList(list) {
    mList->addData(this);
}
ByamlWriterBigData::~ByamlWriterBigData() = default;
void ByamlWriterBigData::write(sead::WriteStream* stream) const {
    stream->writeU32(mOffset);
}
u32 ByamlWriterBigData::calcBigDataSize() const {return 8;}
void ByamlWriterBigData::writeBigData(sead::WriteStream*) const {}

}
