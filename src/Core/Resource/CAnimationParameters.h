#ifndef CANIMATIONPARAMETERS_H
#define CANIMATIONPARAMETERS_H

#include "CAnimSet.h"
#include "EGame.h"
#include "TResPtr.h"
#include "Core/Resource/Model/CModel.h"

class CAnimationParameters
{
    EGame mGame;
    TResPtr<CAnimSet> mpCharSet;

    u32 mNodeIndex;
    u32 mUnknown1;
    u32 mUnknown2;
    u32 mUnknown3;
    u32 mUnknown4;

public:
    CAnimationParameters();
    CAnimationParameters(IInputStream& SCLY, EGame Game);
    CModel* GetCurrentModel(s32 NodeIndex = -1);
    TString GetCurrentCharacterName(s32 NodeIndex = -1);

    // Getters
    EGame Version();
    CAnimSet* AnimSet();
    u32 CharacterIndex();
    u32 Unknown(u32 index);

    // Setters
    void SetResource(CResource *pRes);
    void SetNodeIndex(u32 Index);
    void SetUnknown(u32 Index, u32 Value);

    // Operators
    inline bool operator==(const CAnimationParameters& rkOther) const
    {
        return ( (mGame == rkOther.mGame) &&
                 (mpCharSet == rkOther.mpCharSet) &&
                 (mNodeIndex == rkOther.mNodeIndex) &&
                 (mUnknown1 == rkOther.mUnknown1) &&
                 (mUnknown2 == rkOther.mUnknown2) &&
                 (mUnknown3 == rkOther.mUnknown3) &&
                 (mUnknown4 == rkOther.mUnknown4) );
    }
};

#endif // CANIMATIONPARAMETERS_H
