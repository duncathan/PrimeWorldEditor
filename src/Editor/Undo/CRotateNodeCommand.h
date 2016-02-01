#ifndef CROTATENODECOMMAND_H
#define CROTATENODECOMMAND_H

#include "IUndoCommand.h"
#include "Editor/INodeEditor.h"
#include <Core/Scene/CSceneNode.h>
#include <QList>

class CRotateNodeCommand : public IUndoCommand
{
    struct SNodeRotate
    {
        CSceneNode *pNode;
        CVector3f initialPos;
        CQuaternion initialRot;
        CVector3f newPos;
        CQuaternion newRot;
    };
    QList<SNodeRotate> mNodeList;
    INodeEditor *mpEditor;
    bool mCommandEnded;

public:
    CRotateNodeCommand();
    CRotateNodeCommand(INodeEditor *pEditor, const QList<CSceneNode*>& nodes, const CVector3f& pivot, const CQuaternion& delta, ETransformSpace transformSpace);
    ~CRotateNodeCommand();
    int id() const;
    bool mergeWith(const QUndoCommand *other);
    void undo();
    void redo();
    bool AffectsCleanState() const { return true; }
    static CRotateNodeCommand* End();
};

#endif // CROTATENODECOMMAND_H
