#pragma once

#include <QtWidgets/QDialog>
#include <QStandardItemModel>
#include "ui_plugincenter.h"
#include "opm_types.h"

class OPMMainWindow : public QDialog
{
Q_OBJECT

public:
	OPMMainWindow(QWidget *parent = nullptr);
	~OPMMainWindow();

public:
	void showOPMWindow();

private:
	void createTreeItem();
	void addNodeToModel(QStandardItem *parentItem, const TreeNode &node);

private:
	Ui::OBSPluginManagement ui;
	QStandardItemModel *m_treeModel;
};
