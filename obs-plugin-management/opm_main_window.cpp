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
    loadInstalledPlugin();
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
    TreeItemDelegate *delegate = new TreeItemDelegate();
    delegate->setTreeView(ui.treeView);
    ui.treeView->setItemDelegate(delegate); 
    ui.treeView->setHeaderHidden(true);
    ui.treeView->setIndentation(0);

    for (const auto &topLevelNode : tree.children) {
	    addNodeToModel(m_treeModel->invisibleRootItem(), topLevelNode);
    }
}

void OPMMainWindow::loadInstalledPlugin() {
    obs_enum_sources(
	    [](void *param, obs_source_t *source) {
		    OPMMainWindow::ObsObjects *obsObjs =
			    static_cast<OPMMainWindow::ObsObjects *>(param);

		    const char *source_id = obs_source_get_id(source);
		    const char *source_name = obs_source_get_name(source);
		    obs_source_type type = obs_source_get_type(source);
		    obs_module_t *_module = obs_get_module(source_name);

		    if (_module && obsObjs) {
			    if (type == OBS_SOURCE_TYPE_INPUT) {
				    std::shared_ptr<ObsPluginDataSource> s =
					   std::make_shared<ObsPluginDataSource>();
				    s->source = source;
				    s->bin_path =
					    QString(obs_get_module_binary_path(_module));
				    s->data_path = QString(
					    obs_get_module_data_path(_module));
				    s->file = QString(obs_get_module_file_name(_module));
				    s->mod_name = QString(
					    obs_get_module_name(_module));
				    obsObjs->sources.push_back(s);
			    } else if (type == OBS_SOURCE_TYPE_FILTER) {
				    std::shared_ptr<ObsPluginDataSource> s =
					    std::make_shared<
						    ObsPluginDataSource>();
				    s->source = source;
				    s->bin_path =
					    QString(obs_get_module_binary_path(
						    _module));
				    s->data_path = QString(
					    obs_get_module_data_path(_module));
				    s->file = QString(
					    obs_get_module_file_name(_module));
				    s->mod_name = QString(
					    obs_get_module_name(_module));
				    obsObjs->filters.push_back(s);
			    } else if (type == OBS_SOURCE_TYPE_TRANSITION) {
				    std::shared_ptr<ObsPluginDataSource> s =
					    std::make_shared<
						    ObsPluginDataSource>();
				    s->source = source;
				    s->bin_path =
					    QString(obs_get_module_binary_path(
						    _module));
				    s->data_path = QString(
					    obs_get_module_data_path(_module));
				    s->file = QString(
					    obs_get_module_file_name(_module));
				    s->mod_name = QString(
					    obs_get_module_name(_module));
				    obsObjs->transitions.push_back(s);
			    }
		    }

		    return true;

	    },
	    &obsObjs);

     obs_enum_encoders(
	    [](void *param, obs_encoder_t *encoder) {
		    ObsObjects *obsObjects = static_cast<ObsObjects *>(param);

		    const char *source_id = obs_encoder_get_id(encoder);
		    const char *encoder_name = obs_encoder_get_name(encoder);
		    obs_module_t *_module = obs_get_module(encoder_name);

		    if (_module && obsObjects) {
			    std::shared_ptr<ObsPluginDataEncoder> s =
				    std::make_shared<ObsPluginDataEncoder>();
			    s->encoder = encoder;
			    s->bin_path = QString(
				    obs_get_module_binary_path(_module));
			    s->data_path =
				    QString(obs_get_module_data_path(_module));
			    s->file =
				    QString(obs_get_module_file_name(_module));
			    s->mod_name = QString(obs_get_module_name(_module));
			    obsObjects->encoders.push_back(s);
		    }
		  
		    return true;
	    },
	    &obsObjs);
}

QStandardItem* OPMMainWindow::findInstalledItem(const TreeItemClass& itemClass)
{
    QStandardItem *rootItem = m_treeModel->invisibleRootItem();

    return findItem(rootItem, itemClass);
}

QStandardItem *OPMMainWindow::findOnlineItem(const TreeItemClass &itemClass)
{
    QStandardItem *rootItem = m_treeModel->invisibleRootItem();

    return findItem(rootItem, itemClass);
}

QStandardItem *OPMMainWindow::findItem(QStandardItem *parent,
				       const TreeItemClass &itemClass)
{
    for (int i = 0; i < parent->rowCount(); ++i) {
	    QStandardItem *child = parent->child(i);
	    QJsonObject obj = child->data(Qt::UserRole).toJsonObject();

	    if (static_cast<TreeItemClass>(obj.value("level").toInt()) == itemClass) {
		    return child; 
	    }


	    QStandardItem *found = findItem(child, itemClass);
	    if (found) {
		    return found;
	    }
    }

    return nullptr;
}
