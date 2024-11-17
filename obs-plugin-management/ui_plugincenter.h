/********************************************************************************
** Form generated from reading UI file 'plugincenter.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
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
            OBSPluginManagement->setObjectName("OBSPluginManagement");
        OBSPluginManagement->resize(1092, 706);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OBSPluginManagement->sizePolicy().hasHeightForWidth());
        OBSPluginManagement->setSizePolicy(sizePolicy);
        OBSPluginManagement->setMinimumSize(QSize(1000, 700));
        OBSPluginManagement->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(OBSPluginManagement);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        searchEdit = new QLineEdit(OBSPluginManagement);
        searchEdit->setObjectName("searchEdit");

        horizontalLayout->addWidget(searchEdit);

        searchButton = new QPushButton(OBSPluginManagement);
        searchButton->setObjectName("searchButton");

        horizontalLayout->addWidget(searchButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        treeView = new QTreeView(OBSPluginManagement);
        treeView->setObjectName("treeView");
        treeView->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_4->addWidget(treeView);

        listView = new QListView(OBSPluginManagement);
        listView->setObjectName("listView");
        listView->setMaximumSize(QSize(550, 16777215));

        horizontalLayout_4->addWidget(listView);

        pluginInfo = new QLabel(OBSPluginManagement);
        pluginInfo->setObjectName("pluginInfo");
        pluginInfo->setMaximumSize(QSize(16777215, 16777215));
        pluginInfo->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_4->addWidget(pluginInfo);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        website = new QLabel(OBSPluginManagement);
        website->setObjectName("website");

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
