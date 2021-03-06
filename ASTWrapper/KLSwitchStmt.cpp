// Copyright (c) 2010-2016, Fabric Software Inc. All rights reserved.

#include "KLSwitchStmt.h"

#include <vector>
#include <string>

using namespace FabricServices::ASTWrapper;

KLSwitchStmt::KLSwitchStmt(const KLFile* klFile, JSONData data, KLStmt * parent)
: KLStmt(klFile, data, parent)
{
  JSONData cases = getArrayDictValue("cases");
  if(cases)
  {
    for(uint32_t i=0;i<cases->getArraySize();i++)
      constructChild(cases->getArrayElement(i));
  }
}

KLDeclType KLSwitchStmt::getDeclType() const
{
  return KLDeclType_SwitchStmt;
}

bool KLSwitchStmt::isOfDeclType(KLDeclType type) const
{
  if(type == KLDeclType_SwitchStmt)
    return true;
  return KLStmt::isOfDeclType(type);
}
