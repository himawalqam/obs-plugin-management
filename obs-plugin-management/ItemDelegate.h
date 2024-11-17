#ifndef TREENODE_H
#define TREENODE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
#include <QTreeView>
#include <QMouseEvent>
#include <QEvent>
#include <QApplication>
#include <QStandardItem>

class TreeItemDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    explicit TreeItemDelegate(QObject *parent = nullptr);
    void setTreeView(QTreeView *treeView);

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
     QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
     bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

signals:
     void expanded(const QModelIndex &index ,bool isExpanded);
private:
private slots:
    void onExpandedTree(const QModelIndex & index,bool isExpanded);
private:
    QTreeView *m_treeView = NULL;
    int m_pixmapWidth = 16;
    int m_pixmapHeight = 10;
    int m_leavel = 0;
    QModelIndex *m_index;
    QString m_expandIconName;
    QString m_collapseIconName;

};

#endif // TREENODE_H
