#include <QGraphicsView>

#include "attachTree.h"
#include "shapeFactory.h"
#include "shapeBase.h"
#include "paramMgr.h"

namespace at
{


TreeNode::TreeNode(TreeNode *parent, int parent_attach_point_idx)
    : m_parent(parent)
    , m_parent_attach_point_idx(parent_attach_point_idx)
    , m_children(nullptr)
{

}

TreeNode::~TreeNode()
{
    if(!m_children)
    {
        int size = m_attach_points.size();
        for(int i = 0; i < size * 4; i++)
        {
            std::vector<TreeNode*>  children = m_children[i];
            for(std::vector<TreeNode*>::const_iterator iterator = children.begin(); iterator != children.end(); ++iterator)
            {
                    delete *iterator;
            }
        }
    }
    delete m_shape;
}

TreeNode *TreeNode::add_child(const std::string &shape_name, NodeDirection node_direction, NodeType node_type, ly::LayerInfo *layer, int parent_attach_point_idx)
{
    if(!m_children)
    {
        m_children = new std::vector<TreeNode*>[m_attach_points.size() * 4];
    }

    TreeNode *child = new TreeNode(this, parent_attach_point_idx);

    child->m_node_type = node_type;
    child->m_node_direction = node_direction;
    child->mp_layer = layer;
    child->m_shape = sp::ShapeFactory::instance()->create_shape(shape_name);

    m_children[parent_attach_point_idx * 4 + node_direction].push_back(child);

    update();

    return child;
}

void TreeNode::remove()
{
    std::vector<TreeNode*> &children = m_parent->m_children[m_parent_attach_point_idx * 4 + m_node_direction];
    std::vector<TreeNode*>::const_iterator i;
    for(i = children.begin(); i != children.end(); ++i)
    {
        if((*i) == this)
        {
            break;
        }
    }

    if(i != children.end())
    {
        children.erase(i);
        delete this;
    }

    m_parent->update();
}

std::vector<pm::ParamDecl *> TreeNode::params() const
{
    return m_shape->get_params_decl();
}

void TreeNode::set_params(std::vector<pm::ParamDecl *> params)
{
    m_shape->set_params(mp_param_mgr, params);

    update();
}

void TreeNode::update()
{
    if(!m_parent)
    {
        m_parent->update();
    }
}

AttachTree::AttachTree(QGraphicsView *view, pm::ParamMgr *param_mgr)
    : TreeNode()
    , mp_view(view)
{
    mp_layer = nullptr;
    m_node_type = NodeType::location;
    m_attach_points = {{0., 0.}};
    mp_param_mgr = param_mgr;
}

AttachTree::~AttachTree()
{

}

void AttachTree::update()
{
    //mp_view->scene()->clear();

    // 构造graphic items here.

    //todo

    //mp_view->update();
}

void AttachTree::remove()
{
    // do nothing.
    // root cant be removed.
}




}
