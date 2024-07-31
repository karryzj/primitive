#include <QGraphicsView>
#include <QVBoxLayout>
#include <QPushButton>
#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "shapeFactory.h"
#include "paramMgr.h"
#include "paramDecl.h"
#include "shapeBase.h"
#include "attachTree.h"
#include "layInfo.h"
#include "layerMgr.h"
#include "primitiveMgr.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建主窗口的中心部件
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *openPopupButton = new QPushButton("Open Popup", this);
    layout->addWidget(openPopupButton);

    setCentralWidget(centralWidget);

    // 连接按钮点击事件到打开弹出窗口的槽函数
    connect(openPopupButton, &QPushButton::clicked, this, &MainWindow::openPopup);

    // 设置主窗口的图标
    setWindowIcon(QIcon(":/img/favicon.png"));
    //全局参数设置
    pm::ParamMgr *mgr = new pm::ParamMgr();
    mgr->add_param(new pm::ParamDecl("x", new QVariant(50), "x"));
    mgr->add_param(new pm::ParamDecl("y", new QVariant(100), "y"));


    //初始化view and scene here
    // todo
    // better use the customed subclass .
    QGraphicsView *view;

    at::AttachTree *tree = new at::AttachTree(view, mgr);

    ly::LayerInfo *layerInfo = new ly::LayerInfo();
    at::TreeNode *node = tree->add_child("rect", at::TreeNode::NodeDirection::leftTop, at::TreeNode::NodeType::add, layerInfo, 0);

    //展示默认参数列表
    std::vector<pm::ParamDecl*> rect_params = node->params();

    //设置图形参数
    rect_params.at(0)->reset_value(new QVariant(100));
    rect_params.at(1)->reset_value(new QVariant(200));
    node->set_params(rect_params);

    //绘制
    tree->update();


}

void MainWindow::openPopup()
{
    ly::PrimitiveMgr *popupWindow = new ly::PrimitiveMgr(this);

    popupWindow->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
