#include <obs-module.h>
#include "opm_main_window.h"
#include "ItemDelegate.h"
#include <QJsonObject>

TreeNode tree{
	TreeItemClass::Root, 1,true, "root", {
		{
			TreeItemClass::Installed, 2,true, "opm.installed", {},
		},

		{
			TreeItemClass::Online, 2, false,"opm.online", {
				{ TreeItemClass::OnlineSource, 3, false,"opm.onlinesource", {} },
				{ TreeItemClass::OnlineOutput, 3, false,"opm.onlineoutput", {} },
				{ TreeItemClass::OnlineEncoder, 3,false, "opm.onlineencoder", {} },
				{ TreeItemClass::OnlineService, 3,false, "opm.onlineservice", {} },
				{ TreeItemClass::OnlineFilter, 3,false, "opm.onlinefilter", {} },
				{ TreeItemClass::OnlineTransition, 3,true, "opm.onlinetransition", {} },
			}
		},

		{TreeItemClass::About, 2, true, "opm.about", {}},
	}
};

OPMMainWindow::OPMMainWindow(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);

    setWindowTitle(QString(obs_module_text("opm.PluginCenterWindowText")));
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint &
		   ~Qt::WindowMinimizeButtonHint);

    createTreeItem();
}

OPMMainWindow::~OPMMainWindow() {

}

void OPMMainWindow::showOPMWindow()
{
    setVisible(true);
}

void OPMMainWindow::addNodeToModel(QStandardItem *parentItem,
				   const TreeNode &node)
{
    QStandardItem *item = new QStandardItem(QString(obs_module_text(node.name)));
    {
	    QJsonObject obj;
	    obj["level"] = node.level;
	    obj["class"] = static_cast<int>(node.itemClass);
	    obj["last"] = node.lastNode;
	    QVariant data = QVariant::fromValue(obj);
	    item->setData(data, Qt::UserRole);
    }
    item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    parentItem->appendRow(item);

    if (node.children.size() > 0) {
	    for (const auto &child : node.children) {
		    addNodeToModel(item, child);
	    }
    }
}

void OPMMainWindow::createTreeItem()
{
    ui.treeView->setStyleSheet(
	    "background-color:rgba(255,255,255,0.001);border:0px");

    m_treeModel = new QStandardItemModel();
    ui.treeView->setModel(m_treeModel);
    //ui.treeView->header()->hide();
    TreeItemDelegate *delegate = new TreeItemDelegate();
    delegate->setTreeView(ui.treeView);
    ui.treeView->setItemDelegate(delegate); 
    ui.treeView->setHeaderHidden(true);
    ui.treeView->setIndentation(0);

    for (const auto &topLevelNode : tree.children) {
	    addNodeToModel(m_treeModel->invisibleRootItem(), topLevelNode);
    }

    /*

    QStandardItem *installed = new QStandardItem(
	    QString(obs_module_text("opm.installed")));
    installed->setData(TreeItemClassInstalled,
		       Qt::UserRole);
    m_treeModel->appendRow(installed);

    QStandardItem *online =
	    new QStandardItem(QString(obs_module_text("opm.online")));
    online->setData(TreeItemClassOnline, Qt::UserRole);

    QStandardItem *onlineSource =
	    new QStandardItem(QString(obs_module_text("opm.onlinesource")));
    onlineSource->setData(TreeItemClassOnlineSource, Qt::UserRole);
    online->appendRow(onlineSource);

    QStandardItem *onlineOutput=
	    new QStandardItem(QString(obs_module_text("opm.onlineoutput")));
    onlineOutput->setData(TreeItemClassOnlineOutput, Qt::UserRole);
    online->appendRow(onlineOutput);

    QStandardItem *onlineEncoder =
	    new QStandardItem(QString(obs_module_text("opm.onlineencoder")));
    onlineEncoder->setData(TreeItemClassOnlineEncoder, Qt::UserRole);
    online->appendRow(onlineEncoder);

     QStandardItem *onlineService=
	    new QStandardItem(QString(obs_module_text("opm.onlineservice")));
    onlineService->setData(TreeItemClassOnlineService, Qt::UserRole);
     online->appendRow(onlineService);

    m_treeModel->appendRow(online);


    QStandardItem *about =
	    new QStandardItem(QString(obs_module_text("opm.about")));
    about->setData(TreeItemClassOnline, Qt::UserRole);
    m_treeModel->appendRow(about);

    //1级目录
    {
	    QJsonObject obj;
	    obj["level"] = 1;
	    QVariant data = QVariant::fromValue(obj);
	    root->setData(data);
    }

    //2级目录
    QStringList list2;
    list2 << QStringLiteral("猎杀小学生部") << QStringLiteral("猎杀妹妹部")
	  << QStringLiteral("猎杀创业者部");
    //3级目录
    QStringList list3;
    list3 << QStringLiteral("张三") << QStringLiteral("李四")
	  << QStringLiteral("王麻子") << QStringLiteral("猴哥")
	  << QStringLiteral("狗哥") << QStringLiteral("天狗哥")
	  << QStringLiteral("花藤哥") << QStringLiteral("乌鸡哥")
	  << QStringLiteral("陈浩南哥");

    for (int i = 0; i < list2.size(); i++) {
	    QStandardItem *item2 = new QStandardItem(list2.at(i));
	    QJsonObject obj;
	    obj["level"] = 2;
	    QVariant data = QVariant::fromValue(obj);
	    item2->setData(data);
	    root->appendRow(item2);

	    for (int j = 0; j < list3.size(); j++) {
		    QStandardItem *item3 = new QStandardItem(list3.at(j));
		    QJsonObject obj;
		    obj["level"] = 3;
		    if (j == list3.size() - 1) {
			    obj["end"] = 1; //绘制结尾圆角标识
		    }
		    QVariant data = QVariant::fromValue(obj);
		    item3->setData(data);
		    item2->appendRow(item3);
	    }
    }

    m_tree->setModel(m_treeModel);
    treeNode *node = new treeNode();
    node->setTreeView(m_tree);
    m_tree->setItemDelegate(node); //设置item的代理
    m_tree->setHeaderHidden(true);
    m_tree->setIndentation(0); //设置树每一级的缩进为0*/
}
