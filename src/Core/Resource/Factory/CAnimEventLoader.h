#ifndef CANIMEVENTLOADER_H
#define CANIMEVENTLOADER_H

#include "Core/Resource/Animation/CAnimEventData.h"
#include "Core/Resource/TResPtr.h"
#include <memory>

class CAnimEventLoader
{
    TResPtr<CAnimEventData> mpEventData;
    EGame mGame;

    CAnimEventLoader() {}
    void LoadEvents(IInputStream& rEVNT);
    int32 LoadEventBase(IInputStream& rEVNT);
    void LoadLoopEvent(IInputStream& rEVNT);
    void LoadUserEvent(IInputStream& rEVNT);
    void LoadEffectEvent(IInputStream& rEVNT);
    void LoadSoundEvent(IInputStream& rEVNT);

public:
    static std::unique_ptr<CAnimEventData> LoadEVNT(IInputStream& rEVNT, CResourceEntry *pEntry);
    static CAnimEventData* LoadAnimSetEvents(IInputStream& rANCS);
    static CAnimEventData* LoadCorruptionCharacterEventSet(IInputStream& rCHAR);
};

#endif // CANIMEVENTLOADER_H
