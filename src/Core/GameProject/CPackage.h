#ifndef CPACKAGE
#define CPACKAGE

#include <Common/CFourCC.h>
#include <Common/CUniqueID.h>
#include <Common/TString.h>

class CGameProject;

struct SNamedResource
{
    TString Name;
    CUniqueID ID;
    CFourCC Type;
};

class CResourceCollection
{
    TString mName;
    std::vector<SNamedResource> mNamedResources;

public:
    CResourceCollection() : mName("UNNAMED") {}
    CResourceCollection(const TString& rkName) : mName(rkName) {}

    inline TString Name() const                                 { return mName; }
    inline u32 NumResources() const                             { return mNamedResources.size(); }
    inline const SNamedResource& ResourceByIndex(u32 Idx) const { return mNamedResources[Idx]; }

    inline void AddResource(const TString& rkName, const CUniqueID& rkID, const CFourCC& rkType)
    {
        mNamedResources.push_back( SNamedResource { rkName, rkID, rkType } );
    }
};

class CPackage
{
    CGameProject *mpProject;
    TString mPakName;
    TWideString mPakPath;
    std::vector<CResourceCollection*> mCollections;

    enum EPackageDefinitionVersion
    {
        eVer_Initial,

        eVer_Max,
        eVer_Current = eVer_Max - 1
    };

public:
    CPackage() {}

    CPackage(CGameProject *pProj, const TString& rkName, const TWideString& rkPath)
        : mpProject(pProj)
        , mPakName(rkName)
        , mPakPath(rkPath)
    {}

    void Load();
    void Save();

    TWideString DefinitionPath(bool Relative) const;
    TWideString CookedPackagePath(bool Relative) const;

    CResourceCollection* AddCollection(const TString& rkName);
    void RemoveCollection(CResourceCollection *pCollection);
    void RemoveCollection(u32 Index);

    // Accessors
    inline TString Name() const                                     { return mPakName; }
    inline TWideString Path() const                                 { return mPakPath; }
    inline u32 NumCollections() const                               { return mCollections.size(); }
    inline CResourceCollection* CollectionByIndex(u32 Idx) const    { return mCollections[Idx]; }

    inline void SetPakName(TString NewName) { mPakName = NewName; }
};

#endif // CPACKAGE

