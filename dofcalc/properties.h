#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QtCore>

enum Orientation {Album, Book};
Q_DECLARE_METATYPE(Orientation);

template<class T>
class PropertyValue
{
private:
    T minVal, maxVal, defVal, val;
public:
    PropertyValue(): minVal(0), maxVal(0), defVal(0), val(0) {}
    PropertyValue& operator = (const PropertyValue &src)
    {
        minVal = src.min();
        maxVal = src.max();
        defVal = src.defaults();
        val = src.value();
        return *this;
    }
    bool valid() const {return minVal<maxVal && minVal<=defVal && defVal<=maxVal;}
    void reset() {if (valid()) setValue(defVal);}
    T min() const {return minVal;}
    T max() const {return maxVal;}
    T defaults() const {return defVal;}
    T value() const {return val;}
    void setValue(T value)
    {
        if (value<minVal) value=minVal; if (value>maxVal) value=maxVal; val=value;
    }
    void set(T min, T max, T def)
    {
        minVal = min; maxVal = max; defVal = def; setValue(defVal);
    }
    void set(T min, T max, T def, T value)
    {
        minVal = min; maxVal = max; defVal = def; setValue(value);
    }
    bool importFromJSON(const QJsonObject &json);
    QJsonObject exportToJSON() const;
};

template<class T>
class PropertySwitch
{
public:
    struct SwitchPair
    {
        QString title;
        T value;
        SwitchPair(): title(), value(0) {}
        SwitchPair(QString t, T v): title(t), value(v) {}
        SwitchPair& operator = (const SwitchPair &src)
        {
            title = src.title; value = src.value; return *this;
        }
    };
private:
    QList<SwitchPair> list;
    int currentIndex;
protected:
    bool indexValid(int i) const {return i >= 0 && i < count();}
    int validateIndex(int i) const
    {
        if (i<-1) i=-1; if (i>=count()) i=count()-1; return i;
    }
public:
    PropertySwitch(): currentIndex(-1) {}
    PropertySwitch& operator = (const PropertySwitch &src)
    {
        list = src.list;
        currentIndex = src.currentIndex;
        return *this;
    }
    void addEntry(SwitchPair entry) {list.append(entry);}
    void addEntry(QString title, T value) {addEntry(SwitchPair(title, value));}
    void delEntry(int i)
    {
        if (indexValid(i)) {list.removeAt(i); validateIndex(currentIndex);}
    }
    int  count() const {return list.count();}
    void clear() {list.clear(); currentIndex = -1;}
    const SwitchPair& operator[] (int i) const
    {
        assert(indexValid(i)); return list.at(i);
    }
    QStringList titleList() const
    {
        QStringList sl;
        for (int i = 0; i < count(); i++) sl.append(list.at(i).title);
        return sl;
    }
    int  index() const {return currentIndex;}
    void setIndex(int i) {currentIndex = validateIndex(i);}
    void setIndexByTitle(QString title)
    {
        for (int i = 0; i < count(); i++)
        {
            if (list.at(i).title == title) {currentIndex = i; return;}
        }
        currentIndex = -1;
    }
    void setIndexByValue(T value)
    {
        for (int i = 0; i < count(); i++)
        {
            if (list.at(i).value == value) {currentIndex = i; return;}
        }
        currentIndex = -1;
    }
    QString title() const
    {
        assert(indexValid(currentIndex));
        return list.at(currentIndex).title;
    }
    T value() const
    {
        assert(indexValid(currentIndex));
        return list.at(currentIndex).value;
    }
    bool importFromJSON(const QJsonObject &json);
    QJsonObject exportToJSON() const;
};

class PropertyList
{
public:
    PropertySwitch<QString> background;
    PropertySwitch<QString> model;
    PropertySwitch<Orientation> orientation;
    PropertySwitch<double> crop;
    PropertyValue<double> cropFactor;
    PropertyValue<double> modelDistance;
    PropertyValue<double> backgroundDistance;
    PropertyValue<double> focalLength;
    PropertyValue<double> diaphragm;
public:
    PropertyList& operator = (const PropertyList &src)
    {
        background = src.background;
        model = src.model;
        orientation = src.orientation;
        crop = src.crop;
        cropFactor = src.cropFactor;
        modelDistance = src.modelDistance;
        backgroundDistance = src.backgroundDistance;
        focalLength = src.focalLength;
        diaphragm = src.diaphragm;
        return *this;
    }
    bool importFromJSON(const QJsonObject &json);
    QJsonObject exportToJSON() const;
};

#endif // PROPERTIES_H
