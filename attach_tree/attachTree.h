#ifndef ATTACHTREE_H
#define ATTACHTREE_H

#include <QObject>

QT_BEGIN_NAMESPACE
class QGraphicsView;
QT_END_NAMESPACE

namespace ly
{
class LayerInfo;
}

namespace pm
{
class ParamDecl;
class ParamMgr;
}

namespace sp
{

class ShapeBase;

}

namespace at
{

class TreeNode
{
public:
    // node type.
    enum NodeType{location, add, del};
    // node direction of one parent-attach-point
    enum NodeDirection{leftTop, leftDown, rightDown, rightTop};

protected:
    TreeNode(TreeNode *parent = nullptr, int parent_attach_point_idx = -1);

public:
    virtual ~TreeNode();


    //del current and its children
    virtual void remove();

    virtual TreeNode *add_child(const std::string &shape_name, NodeDirection node_direction, NodeType node_type, ly::LayerInfo *layer, int parent_attach_point_idx);


    NodeType node_type() const;
    int layer() const;

    //params
    std::vector<pm::ParamDecl*> params() const;
    void set_params(std::vector<pm::ParamDecl*> params);

    //attach points
    std::vector<QPointF> attach_points();
    std::vector<QPointF> attach_coord_points();

    //node is updated.
    virtual void update();


protected:

    //parent
    TreeNode *m_parent;
    int m_parent_attach_point_idx;
    pm::ParamMgr *mp_param_mgr;

    // children. 4 treenode for one parent-attach-point . order: leftTop, leftDown, rightDown, rightTop
    std::vector<TreeNode*> *m_children;

    //node info
    NodeDirection m_node_direction;
    NodeType m_node_type;
    ly::LayerInfo *mp_layer;


    //shape
    sp::ShapeBase *m_shape;
    std::vector<QPointF> m_attach_points;

};




class AttachTree : public QObject, public TreeNode
{
    Q_OBJECT
public:
    AttachTree(QGraphicsView *view, pm::ParamMgr *param_mgr);
    ~AttachTree();

    void update() override;
    void remove() override;




private:
    QGraphicsView *mp_view;

};


}


#endif // ATTACHTREE_H
