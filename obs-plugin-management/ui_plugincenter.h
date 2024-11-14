/********************************************************************************
** Form generated from reading UI file 'plugincenter.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINCENTER_H
#define UI_PLUGINCENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OBSPluginManagement
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QTreeView *treeView;
    QListView *listView;
    QLabel *pluginInfo;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *website;

    void setupUi(QDialog *OBSPluginManagement)
    {
        if (OBSPluginManagement->objectName().isEmpty())
            OBSPluginManagement->setObjectName(QString::fromUtf8("OBSPluginManagement"));
        OBSPluginManagement->resize(1219, 768);
        OBSPluginManagement->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(OBSPluginManagement);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        searchEdit = new QLineEdit(OBSPluginManagement);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));

        horizontalLayout->addWidget(searchEdit);

        searchButton = new QPushButton(OBSPluginManagement);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout->addWidget(searchButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        treeView = new QTreeView(OBSPluginManagement);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_4->addWidget(treeView);

        listView = new QListView(OBSPluginManagement);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMaximumSize(QSize(650, 16777215));

        horizontalLayout_4->addWidget(listView);

        pluginInfo = new QLabel(OBSPluginManagement);
        pluginInfo->setObjectName(QString::fromUtf8("pluginInfo"));
        pluginInfo->setMaximumSize(QSize(16777215, 16777215));
        pluginInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_4->addWidget(pluginInfo);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        website = new QLabel(OBSPluginManagement);
        website->setObjectName(QString::fromUtf8("website"));

        horizontalLayout_5->addWidget(website);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(OBSPluginManagement);

        QMetaObject::connectSlotsByName(OBSPluginManagement);
    } // setupUi

    void retranslateUi(QDialog *OBSPluginManagement)
    {
        OBSPluginManagement->setWindowTitle(QCoreApplication::translate("OBSPluginManagement", "Dialog", nullptr));
        searchButton->setText(QCoreApplication::translate("OBSPluginManagement", "Search", nullptr));
        pluginInfo->setText(QString());
        website->setText(QCoreApplication::translate("OBSPluginManagement", "https://www.test.com", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OBSPluginManagement: public Ui_OBSPluginManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINCENTER_H
