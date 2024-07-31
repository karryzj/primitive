#include <QToolBar>
#include <QDockWidget>
#include <QTreeWidget>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGraphicsTextItem>
#include <PriDrawRectangleShapeAction.h>
#include <PriDrawTriangleShapeAction.h>
#include <PriDrawQuadrangleShapeAction.h>
#include <PriDrawCircleShapeAction.h>
#include <PriDrawSectorShapeAction.h>
#include <PriDrawEllipseShapeAction.h>
#include "layInfo.h"
#include "layListItemWidget.h"
#include "primitiveMgr.h"
#include "priGraphicsView.h"
#include "layerMgr.h"

#define ACTION_NAME_RECTANGLE                   QString("rectangle")
#define ACTION_NAME_TRIANGLE                    QString("triangle")
#define ACTION_NAME_QUADRANGLE                  QString("quadrangle")
#define ACTION_NAME_CIRCLE                      QString("circle")
#define ACTION_NAME_SECTOR                      QString("sector")
#define ACTION_NAME_ELLIPSE                     QString("ellipse")

#define TOOL_BAR_NAME                           tr("工具栏")
#define DRAW_TOOL_BAR_NAME                      tr("绘图工具栏")

namespace ly
{


PrimitiveMgr::PrimitiveMgr(QWidget *parent) : QMainWindow(parent)
{
    QAction *redo_action = new QAction(QIcon(":/img/lay_undo.png"), tr("撤消"), this);
    QAction *undo_action = new QAction(QIcon(":/img/lay_redo.png"), tr("恢复"), this);
    QAction *import_action = new QAction(QIcon(":/img/lay_import.png"), tr("导入"), this);
    QAction *save_action = new QAction(QIcon(":/img/lay_save.png"), tr("保存"), this);

    // 创建工具栏和绘图工具栏
    QToolBar *tool_bar = addToolBar(TOOL_BAR_NAME);
    QAction *separator = tool_bar->addSeparator();
    QToolBar *draw_tool_bar = addToolBar(DRAW_TOOL_BAR_NAME);
    draw_tool_bar->setObjectName(DRAW_TOOL_BAR_NAME);
    QAction *draw_separator = draw_tool_bar->addSeparator();

    tool_bar->addAction(redo_action);
    tool_bar->addAction(undo_action);
    tool_bar->addAction(import_action);
    tool_bar->addAction(save_action);
    // 初始化工具栏上的绘制图形的命令
    initDrawShapeActions();

    // 设置工具栏图标大小
    tool_bar->setIconSize(QSize(32, 32));
    // 设置工具按钮样式，使文字显示在图标下方
    tool_bar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    // 设置工具栏图标大小
    draw_tool_bar->setIconSize(QSize(32, 32));
    // 设置工具按钮样式，使文字显示在图标下方
    draw_tool_bar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    setStyleSheet("QMainWindow::separator {"
                  "background: gray;"
                  "width: 1px;"
                  "height: 1px;"
                  "}");
    // 创建并设置 Dock Widget 的样式
    QString dock_widget_style = "QDockWidget {"
                                "    border: 2px solid #5F9EA0;"  // 边框颜色
                                "    border-radius: 10px;"         // 圆角半径
                                "    background-color: #E0FFFF;"   // 背景颜色
                                "}"
                                "QDockWidget::title {"
                                "    text-align: center;"          // 标题文本居中
                                "    background-color: #5F9EA0;"   // 标题栏背景色
                                "    padding: 5px;"                // 标题栏内边距
                                "    border-top-left-radius: 8px;" // 左上角圆角
                                "    border-top-right-radius: 8px;"// 右上角圆角
                                // "    border-bottom-left-radius: 8px;" // 左上角圆角
                                // "    border-bottom-right-radius: 8px;"// 右上角圆角
                                "}";
    QDockWidget *dock_widget_top = new QDockWidget(tr("图元树型结构"), this);
    dock_widget_top->setStyleSheet(dock_widget_style);
    QTreeWidget *tree_widget = new QTreeWidget(dock_widget_top);

    dock_widget_top->setWidget(tree_widget);
    addDockWidget(Qt::LeftDockWidgetArea, dock_widget_top);

    // // 创建左侧下方框（Dock Widget）
    LayerMgr *dock_bottom_content = new LayerMgr();
    QDockWidget *dock_widget_bottom = new QDockWidget(tr("使用图层"), this);
    dock_widget_bottom->setStyleSheet(dock_widget_style);
    dock_widget_bottom->setWidget(dock_bottom_content);

    // 将第二个框放置在第一个框下面
    splitDockWidget(dock_widget_top, dock_widget_bottom, Qt::Vertical);

    // 创建第一个 Dock Widget
    QDockWidget *param_list_dock = new QDockWidget(tr("参数列表"), this);
    param_list_dock->setStyleSheet(dock_widget_style);
    param_list_dock->setWidget(new QLabel("Content of Dock 1"));
    addDockWidget(Qt::RightDockWidgetArea, param_list_dock);

    // 创建第二个 Dock Widget
    QDockWidget *param_constraints_dock = new QDockWidget(tr("参数约束"), this);
    param_constraints_dock->setStyleSheet(dock_widget_style);
    param_constraints_dock->setWidget(new QLabel("Content of Dock 2"));
    addDockWidget(Qt::RightDockWidgetArea, param_constraints_dock);

    // 创建第三个 Dock Widget
    QDockWidget *coord_anchor_dock = new QDockWidget(tr("坐标锚点"), this);
    coord_anchor_dock->setStyleSheet(dock_widget_style);
    coord_anchor_dock->setWidget(new QLabel("Content of Dock 3"));
    addDockWidget(Qt::RightDockWidgetArea, coord_anchor_dock);

    // 创建第四个 Dock Widget
    QDockWidget *anchor_dock = new QDockWidget(tr("锚点"), this);
    anchor_dock->setStyleSheet(dock_widget_style);
    anchor_dock->setWidget(new QLabel("Content of Dock 4"));
    addDockWidget(Qt::RightDockWidgetArea, anchor_dock);

    // 创建主界面的图形视图（Graphics View）
    mp_graphics_scene = new QGraphicsScene(this);
    mp_graphics_view = new PriGraphicsView(mp_graphics_scene, this);

    // 向场景中添加示例项目
    QGraphicsTextItem *textItem = mp_graphics_scene->addText("Hello, QGraphicsView!");
    textItem->setPos(50, 50); // 设置文本位置

    // 设置中央小部件
    setCentralWidget(mp_graphics_view);

    // 设置主窗口标题
    setWindowTitle(tr("图元编辑"));

    // 最大化主窗口
    showMaximized();
}

PrimitiveMgr::~PrimitiveMgr()
{
    delete mp_graphics_view;
    delete mp_graphics_scene;
}

void PrimitiveMgr::initDrawShapeActions(void)
{
    // 初始化工具栏
    QToolBar* tool_bar = this->findChild<QToolBar*>(DRAW_TOOL_BAR_NAME);
    Q_ASSERT(tool_bar);
    tool_bar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    // 增加命令
    m_draw_shape_actions.insert(std::make_pair(ACTION_NAME_RECTANGLE, new PriDrawRectangleShapeAction(this)));
    tool_bar->addAction(m_draw_shape_actions[ACTION_NAME_RECTANGLE]);
    m_draw_shape_actions.insert(std::make_pair(ACTION_NAME_TRIANGLE, new PriDrawTriangleShapeAction(this)));
    tool_bar->addAction(m_draw_shape_actions[ACTION_NAME_TRIANGLE]);
    m_draw_shape_actions.insert(std::make_pair(ACTION_NAME_QUADRANGLE, new PriDrawQuadrangleShapeAction(this)));
    tool_bar->addAction(m_draw_shape_actions[ACTION_NAME_QUADRANGLE]);
    m_draw_shape_actions.insert(std::make_pair(ACTION_NAME_CIRCLE, new PriDrawCircleShapeAction(this)));
    tool_bar->addAction(m_draw_shape_actions[ACTION_NAME_CIRCLE]);
    m_draw_shape_actions.insert(std::make_pair(ACTION_NAME_SECTOR, new PriDrawSectorShapeAction(this)));
    tool_bar->addAction(m_draw_shape_actions[ACTION_NAME_SECTOR]);
    m_draw_shape_actions.insert(std::make_pair(ACTION_NAME_ELLIPSE, new PriDrawEllipseShapeAction(this)));
    tool_bar->addAction(m_draw_shape_actions[ACTION_NAME_ELLIPSE]);

    // 设置对应的命令文本和Icon。
    for(const auto& pair:m_draw_shape_actions)
    {
        // 设置文本
        QString action_name=pair.first;
        pair.second->setText(action_name);
        // 设置图标
        QIcon icon(":/img/"+action_name +".png");
        pair.second->setIcon(icon);
        // 将绘制图形的action增加到工具栏中
    }

    // 连接 action 的 triggered 信号到槽函数。此处不能通过for循环实现
    connect(m_draw_shape_actions[ACTION_NAME_RECTANGLE], &QAction::triggered, this, [&]()
    {
        drawShape(ACTION_NAME_RECTANGLE);
    });
    connect(m_draw_shape_actions[ACTION_NAME_TRIANGLE], &QAction::triggered, this, [&]()
    {
        drawShape(ACTION_NAME_TRIANGLE);
    });
    connect(m_draw_shape_actions[ACTION_NAME_QUADRANGLE], &QAction::triggered, this, [&]()
    {
        drawShape(ACTION_NAME_QUADRANGLE);
    });
    connect(m_draw_shape_actions[ACTION_NAME_CIRCLE], &QAction::triggered, this, [&]()
    {
        drawShape(ACTION_NAME_CIRCLE);
    });
    connect(m_draw_shape_actions[ACTION_NAME_SECTOR], &QAction::triggered, this, [&]()
    {
        drawShape(ACTION_NAME_SECTOR);
    });
    connect(m_draw_shape_actions[ACTION_NAME_ELLIPSE], &QAction::triggered, this, [&]()
    {
        drawShape(ACTION_NAME_ELLIPSE);
    });
}

void PrimitiveMgr::drawShape(const QString &shape_name)
{
    auto itor = m_draw_shape_actions.find(shape_name);
    Q_ASSERT(itor!=m_draw_shape_actions.end());
    (itor->second)->drawShape();
}

}
