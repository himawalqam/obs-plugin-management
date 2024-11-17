#include "ItemDelegate.h"
#include <QDebug>
#include <QToolTip>
#include "QJsonObject"
#include <QPainterPath>

TreeItemDelegate::TreeItemDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    this->installEventFilter(this);
    m_expandIconName = ":/up.png";
    m_collapseIconName = ":/down.png";
}

void TreeItemDelegate::setTreeView(QTreeView *treeView)
{
    m_treeView = treeView;
    connect(this,SIGNAL(expanded(const QModelIndex &,bool)),this,SLOT(onExpandedTree(const QModelIndex &,bool)));
}

void TreeItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->setRenderHint(QPainter::Antialiasing);
    bool bExpanded = true;
    if (m_treeView != NULL)
    {
        bExpanded = m_treeView->isExpanded(index);
    }

    QJsonObject obj =  index.data(Qt::UserRole).toJsonObject();
    int level = obj.value("level").toInt();

    if(!bExpanded){
        if(level <= 2){

            painter->setPen(Qt::NoPen);
            painter->setBrush(QColor(255,255,255,30));
            QRect rect = QRect(option.rect.x(),option.rect.y()+5,option.rect.width()-10,option.rect.height()-10);
            painter->drawRoundedRect(rect, 10, 10);
            painter->setBrush(QColor(255,255,255,70));

            if(option.state & QStyle::State_MouseOver)
            {
                painter->drawRoundedRect(rect, 10, 10);

            }
        }
        else
        {
            QPainterPath path;
            path.setFillRule( Qt::WindingFill ); 

            bool isLast= obj.value("last").toBool();
	    if (isLast == true )
            {
                QRect rect = QRect(option.rect.x(),option.rect.y()+option.rect.height()/2,option.rect.width()-10,option.rect.height()/2);
                path.addRoundedRect (rect, 10.0, 10.0);
                QPainterPath path1;
                QRect rect2 = QRect(option.rect.x(),option.rect.y(),option.rect.width()-10,option.rect.height()/2+10);
                path.addRect(rect2);
                painter->fillPath(path,  QBrush(QColor(255,255,255,30)));
                if(option.state & QStyle::State_MouseOver)
                {
                    painter->fillPath(path,  QBrush(QColor(255,255,255,70)));

                }
            }
            else{
                QRect rect = QRect(option.rect.x(),option.rect.y(),option.rect.width()-10,option.rect.height());
                path.addRect(rect);
                painter->fillPath(path,  QBrush(QColor(255,255,255,30)));

                if(option.state & QStyle::State_MouseOver)
                {
                    painter->fillPath(path,  QBrush(QColor(255,255,255,70)));

                }
            }
        }
    }
    else
    {
        if(level == 1)
        {
            painter->setPen(Qt::NoPen);
            painter->setBrush(QColor(255,255,255,30));
            QRect rect = QRect(option.rect.x(),option.rect.y()+5,option.rect.width()-10,option.rect.height()-10);
            painter->drawRoundedRect(rect, 10, 10);

            painter->setBrush(QColor(255,255,255,70));

            if(option.state & QStyle::State_MouseOver)
            {
                painter->drawRoundedRect(rect, 10, 10);

            }
        }
        else if(level == 2){
	    const QAbstractItemModel *model = index.model();
	    if (model->hasChildren(index)) {

		QPainterPath path;
		path.setFillRule(Qt::WindingFill);
		QRect rect = QRect(option.rect.x(), option.rect.y() + 5,
				   option.rect.width() - 10,
				   option.rect.height() / 2);
		path.addRoundedRect(rect, 10.0, 10.0);
		QPainterPath path1;
		QRect rect2 = QRect(option.rect.x(), option.rect.y() + 20,
				    option.rect.width() - 10,
				    option.rect.height() - 20);
		path.addRect(rect2);
		painter->fillPath(path, QBrush(QColor(255, 255, 255, 30)));
		if (option.state & QStyle::State_MouseOver) {
		    painter->fillPath(path, QBrush(QColor(255, 255, 255, 70)));
		}
	    } else {
		painter->setPen(Qt::NoPen);
		painter->setBrush(QColor(255, 255, 255, 30));
		QRect rect = QRect(option.rect.x(), option.rect.y() + 5,
				   option.rect.width() - 10,
				   option.rect.height() - 10);
		painter->drawRoundedRect(rect, 10, 10);
		painter->setBrush(QColor(255, 255, 255, 70));

		if (option.state & QStyle::State_MouseOver) {
		    painter->drawRoundedRect(rect, 10, 10);
		}
	    }

        }
        else
        {
            QPainterPath path;
            path.setFillRule( Qt::WindingFill );


            bool isLast = obj.value("last").toBool();
	    if (isLast == true) {
                QRect rect = QRect(option.rect.x(),option.rect.y()+option.rect.height()/2,option.rect.width()-10,option.rect.height()/2);
                path.addRoundedRect (rect, 10.0, 10.0);
                QPainterPath path1;
                QRect rect2 = QRect(option.rect.x(),option.rect.y(),option.rect.width()-10,option.rect.height()/2+10);
                path.addRect(rect2);
                painter->fillPath(path,  QBrush(QColor(255,255,255,30)));
                if(option.state & QStyle::State_MouseOver)
                {
                    painter->fillPath(path,  QBrush(QColor(255,255,255,70)));

                }
            }
            else{
                QRect rect = QRect(option.rect.x(),option.rect.y(),option.rect.width()-10,option.rect.height());
                path.addRect(rect);
                painter->fillPath(path,  QBrush(QColor(255,255,255,30)));

                if(option.state & QStyle::State_MouseOver)
                {
                    painter->fillPath(path,  QBrush(QColor(255,255,255,70)));

                }
            }

        }

    }

    const QAbstractItemModel *model = index.model();
    if (model->hasChildren(index)){
        int height = (option.rect.height() - m_pixmapWidth) / 2;
        QPixmap pixmap = bExpanded ? QPixmap(m_expandIconName) : QPixmap(m_collapseIconName);
        QRect decorationRect = QRect(option.rect.left() + option.rect.width() - 60, option.rect.top() + height, m_pixmapWidth, m_pixmapHeight);
        painter->drawPixmap(decorationRect, pixmap);
    }

    {
        QJsonObject obj =  index.data(Qt::UserRole).toJsonObject();
        int level = obj.value("level").toInt();
        QString type = obj.value("objectType").toString();
        QString Icon;
        QFont font;
        QString text = index.data(Qt::DisplayRole).toString();

        font.setPixelSize(20);
        int textx = 0;

        if(level == 1)
        {
            textx = 20;
            font.setPixelSize(26);
        }
        else if(level == 2)
        {
            textx = 20;
        }
        else if(level == 3)
        {
            textx = 65;

	    painter->setPen(QColor(255,255,255,50));
            painter->drawLine(option.rect.x()+10,option.rect.y(),option.rect.width()-20,option.rect.y());
        }

        QRect textRect = option.rect;
        textRect.setX(textRect.x()+textx);

        painter->setFont(font);
        painter->setPen(QColor(255,255,255));
        painter->drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, text);

        QPixmap pixmap =  QPixmap(Icon);

        QRect decorationRect = QRect(option.rect.x()+ textRect.x()-30, option.rect.y()+option.rect.height()/2 - pixmap.height()/2, pixmap.width(), pixmap.height());
        painter->drawPixmap(decorationRect, pixmap);
    }
}

QSize TreeItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QJsonObject obj =  index.data(Qt::UserRole ).toJsonObject();
    int level = obj.value("level").toInt();
    int height = 65;
    if(level == 1){
        height =70;
    }
    return QSize(option.rect.width(),height);
}

bool TreeItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    int height = (option.rect.height() - m_pixmapWidth) / 2;
    QRect decorationRect = QRect(option.rect.left() + option.rect.width() - 60, option.rect.top() + height, m_pixmapWidth, m_pixmapHeight);

    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
    if (event->type() == QEvent::MouseButtonPress /*&& decorationRect.contains(mouseEvent->pos()*/)
    {
        bool bExpanded = m_treeView->isExpanded(index);

        emit expanded(index,!bExpanded);

    }
    return true;
}

void TreeItemDelegate::onExpandedTree(const QModelIndex &index, bool isExpanded)
{
    if(m_treeView !=NULL)
    {
        m_treeView->setExpanded(index,isExpanded);

    }
}
