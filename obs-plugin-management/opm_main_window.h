#pragma once

#include <QtWidgets/QDialog>
#include <QStandardItemModel>
#include "ui_plugincenter.h"
#include "opm_types.h"
#include <obs.h>
#include <obs-module.h>

class OPMMainWindow : public QDialog
{
Q_OBJECT

public:
	OPMMainWindow(QWidget *parent = nullptr);
	~OPMMainWindow();

	struct ObsPluginData {
		QString mod_name;
		QString file;
		QString bin_path;
		QString data_path;
	};
	struct ObsPluginDataSource : public ObsPluginData {
		const obs_source_t *source;
	};
	struct ObsPluginDataEncoder: public ObsPluginData {
		const obs_encoder_t *encoder;
	};
	struct ObsPluginDataOutput : public ObsPluginData {
		const obs_output_t *output;
	};
	struct ObsPluginDataService: public ObsPluginData {
		const obs_service_t *service;
	};

	struct ObsObjects {
		std::vector<std::shared_ptr<ObsPluginDataSource>> sources; // General Sources
		std::vector<std::shared_ptr<ObsPluginDataSource>> filters;  // Filters
		std::vector<std::shared_ptr<ObsPluginDataSource>>
			transitions;                            // Transitions
		std::vector<std::shared_ptr<ObsPluginDataEncoder>>
			encoders;                               // Encoders
		std::vector<std::shared_ptr<ObsPluginDataOutput>>
			outputs;                              // Outputs
		std::vector<std::shared_ptr<ObsPluginDataService>>
			services; // Services
	};

public:
	void showOPMWindow();
	QStandardItem *findInstalledItem(const TreeItemClass &itemClass);
	QStandardItem *findOnlineItem(const TreeItemClass &itemClass);

private:
	void createTreeItem();
	void loadInstalledPlugin();
	void addNodeToModel(QStandardItem *parentItem, const TreeNode &node);
	QStandardItem *findItem(QStandardItem *parent,
				const TreeItemClass &itemClass);

private:
	Ui::OBSPluginManagement ui;
	QStandardItemModel *m_treeModel;
	ObsObjects obsObjs;
};
