#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QtCore>
#include <QtWidgets>

//enum Orientation {Book, Album};

template<class T>
class PropertyValue
{
private:
    T minVal, maxVal, defVal, val;
public:
    PropertyValue(): minVal(0), maxVal(0), defVal(0), val(0) {}
    PropertyValue(T min, T max, T def):
        minVal(min), maxVal(max), defVal(def), val(def) {}
    PropertyValue(T min, T max, T def, T value):
        minVal(min), maxVal(max), defVal(def), val(value) {}
    PropertyValue& operator = (const PropertyValue &src)
    {
        minVal=src.min();
        maxVal=src.max();
        defVal=src.defaults();
        val=src.value();
    }
    bool valid() {return minVal<maxVal && minVal<=defVal && defVal<=maxVal;}
    void reset() {if (valid()) setValue(defVal);}
    T min() {return minVal;}
    T max() {return maxVal;}
    T defaults() {return defVal;}
    T value() {return val;}
    void setValue(T value)
    {
        if (value<minVal) value=minVal; if (value>maxVal) value=maxVal; val=value;
    }
    void set(T min, T max, T def, T value)
    {
        minVal = min; maxVal = max; defVal = def; setValue(value);
    }
    void setupWidget(QWidget *widget)
    {
        bool blockedState = widget->signalsBlocked();
        widget->blockSignals(true);
        if (dynamic_cast<QDoubleSpinBox*>(widget))
        {
            QDoubleSpinBox *spin = dynamic_cast<QDoubleSpinBox*>(widget);
            spin->setRange(minVal, maxVal);
            spin->setValue(val);
        }
        else if (dynamic_cast<QSlider*>(widget))
        {
            QSlider *slider = dynamic_cast<QSlider*>(widget);
            slider->setRange(minVal, maxVal);
            slider->setValue(val);
        }
        widget->blockSignals(blockedState);
    }
    QJsonObject asJson()
    {
        QJsonObject json;
        json["min"] = min();
        json["max"] = max();
        json["defaults"] = defaults();
        json["value"] = value();
        return json;
    }
    void loadFromJson(QJsonObject json)
    {
        set(json["min"].toDouble(),
            json["max"].toDouble(),
            json["defaults"].toDouble(),
            json["value"].toDouble());
    }
};

template<class T>
class PropertyCombo
{
private:
    QList<QPair<QString, T>> comboList;
    int currentIndex;
    bool indexValid(int idx) {return idx >= 0 && idx < comboList.count();}
public:
    PropertyCombo(): currentIndex(-1) {}
    PropertyCombo& operator = (const PropertyCombo &src)
    {
        comboList = src.comboList;
        currentIndex = src.currentIndex;
    }
    void addEntry(QPair<QString, T> entry)
    {
        comboList.append(entry);
    }
    void addEntry(QString friendlyName, T value)
    {
        addEntry(QPair<QString, T>(friendlyName, value));
    }
    void clear()
    {
        comboList.clear();
        currentIndex = -1;
    }
    QPair<QString, T> operator[] (int idx)
    {
        return indexValid(idx) ? comboList.at(idx) : QPair<QString, T>();
    }
    QStringList friendlyNames()
    {
        QStringList sl;
        for (int i = 0; i < comboList.count(); i++) sl.append(comboList.at(i).first);
        return sl;
    }
    int index() {return currentIndex;}
    void setIndex(int idx) {if (indexValid(idx)) currentIndex = idx;}
    void setIndexByValue(T value)
    {
        for (int i = 0; i < comboList.count(); i++)
        {
            if (comboList.at(i).second == value) {currentIndex = i; return;}
        }
        currentIndex = -1;
    }
    T value() {return (*this)[currentIndex].second;}
    void setupWidget(QWidget *widget)
    {
        bool blockedState = widget->signalsBlocked();
        widget->blockSignals(true);
        if (dynamic_cast<QComboBox*>(widget))
        {
            QComboBox *cb = dynamic_cast<QComboBox*>(widget);
            cb->clear();
            cb->addItems(friendlyNames());
            cb->setCurrentIndex(currentIndex);
        }
        widget->blockSignals(blockedState);
    }
    QJsonObject asJson()
    {
        QJsonObject json, obj;
        QJsonArray array;
        for (int i = 0; i < comboList.count(); i++)
        {
            obj["friendlyName"] = comboList.at(i).first;
            obj["data"] = comboList.at(i).second;
            array.append(obj);
        }
        json["list"] = array;
        json["currentIndex"] = index();
        return json;
    }
    void loadFromJson(QJsonObject json)
    {
        clear();
        QJsonArray array = json["list"].toArray();
        for (int i = 0; i < array.count(); i++)
        {
            QJsonObject obj = array[i].toObject();
            if (obj["friendlyName"].isUndefined() || obj["data"].isUndefined()) continue;
            addEntry(obj["friendlyName"].toString(), obj["data"].toDouble());
        }
        currentIndex = json["currentIndex"].toInt();
    }
};

template<class TC, class TV>
class PropertyComboValue : public PropertyCombo<TC>
{
private:
    PropertyValue<TV> linkedVal;
public:
    void setLinkedRanges(TV min, TV max, TV def)
    {
        linkedVal.set(min, max, def, def);
    }
    TV value() {return linkedVal.value();}
    void setValue(TV value)
    {
        linkedVal.setValue(value);
        PropertyCombo<TC>::setIndexByValue(linkedVal.value());
    }
    void setIndex(int idx)
    {
        PropertyCombo<TC>::setIndex(idx);
        linkedVal.setValue((*this)[idx].second);
    }
    void setIndexByValue(TV value)
    {
        PropertyCombo<TC>::setIndexByValue(value);
        linkedVal.setValue(value);
    }
    void setupWidget(QWidget *widget)
    {
        PropertyCombo<TC>::setupWidget(widget);
        bool blockedState = widget->signalsBlocked();
        widget->blockSignals(true);
        if (dynamic_cast<QDoubleSpinBox*>(widget))
        {
            QDoubleSpinBox *spin = dynamic_cast<QDoubleSpinBox*>(widget);
            spin->setRange(linkedVal.min(), linkedVal.max());
            spin->setValue(linkedVal.value());
        }
        widget->blockSignals(blockedState);
    }
};

class PropertySet
{
public:
    QString name;
    PropertyCombo<QString> background;
    PropertyCombo<QString> model;
    //PropertyCombo<Orientation> orientation; todo
    PropertyComboValue<QString, double> crop;
    PropertyValue<double> backgroudDistance;
    PropertyValue<double> modelDistance;
    PropertyValue<double> focalLenght;
    PropertyValue<double> diaphragm;
    QJsonObject asJSON();
    bool loadFromJSON(QJsonObject &json);
};

#endif // PROPERTIES_H
