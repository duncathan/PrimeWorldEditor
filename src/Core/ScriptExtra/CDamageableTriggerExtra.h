#ifndef CDAMAGEABLETRIGGEREXTRA_H
#define CDAMAGEABLETRIGGEREXTRA_H

#include "CScriptExtra.h"

class CDamageableTriggerExtra : public CScriptExtra
{
    // Render fluid planes for doors in MP1
    enum ERenderSide
    {
        eNoRender = 0,
        eNorth    = 1,
        eSouth    = 2,
        eWest     = 3,
        eEast     = 4,
        eUp       = 5,
        eDown     = 6
    };

    TVector3Property *mpSizeProp;
    TEnumProperty *mpRenderSideProp;
    TFileProperty *mpTextureProps[3];

    CVector3f mPlaneSize;
    ERenderSide mRenderSide;
    TResPtr<CTexture> mpTextures[3];

    CMaterial *mpMat;
    CVector2f mCoordScale;

    float mCachedRayDistance;

public:
    explicit CDamageableTriggerExtra(CScriptObject *pInstance, CScene *pScene, CSceneNode *pParent = 0);
    ~CDamageableTriggerExtra();
    void CreateMaterial();
    void UpdatePlaneTransform();
    void OnTransformed();
    void PropertyModified(IProperty *pProperty);
    bool ShouldDrawNormalAssets();
    void AddToRenderer(CRenderer *pRenderer, const SViewInfo& ViewInfo);
    void Draw(FRenderOptions Options, int ComponentIndex, const SViewInfo& ViewInfo);
    void DrawSelection();
    void RayAABoxIntersectTest(CRayCollisionTester& Tester, const SViewInfo& ViewInfo);
    SRayIntersection RayNodeIntersectTest(const CRay& Ray, u32 ComponentIndex, const SViewInfo& ViewInfo);
};

#endif // CDAMAGEABLETRIGGEREXTRA_H
