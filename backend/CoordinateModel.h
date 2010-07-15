/*
 *  PinpointWCS is developed by the Chandra X-ray Center
 *  Education and Public Outreach Group
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef COORDINATE_MODEL_H
#define COORDINATE_MODEL_H

#include <QAbstractTableModel>
#include <QPair>
#include <QList>
#include <QPointF>

class CoordinateModel : public QAbstractTableModel
{
	
	Q_OBJECT
	
public:
	
	CoordinateModel(QObject *parent=0);
    CoordinateModel(QList< QPair<QPointF, QPointF> > coordPairs, QObject *parent=0);
	~CoordinateModel();
	
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index=QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index=QModelIndex());
	QList< QPair<QPointF, QPointF> > getList();
	
private:
	// Need some type of storage for the data here
	QList< QPair<QPointF, QPointF> > listOfCoordinatePairs;

};

#endif