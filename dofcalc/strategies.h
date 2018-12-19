#ifndef STRATEGIES_H
#define STRATEGIES_H

#include <QString>
#include <QStringList>

template <class T>
struct Triple{
    T min, max, defaultValue;

    Triple(): min(0), max(0), defaultValue(0) {}
    Triple(T _min, T _max, T _def): min(_min), max(_max), defaultValue(_def) {}
    bool Valid() { return min<max && min<=defaultValue && defaultValue <= max; }
};


class Strategy{
public:
    Strategy() {}
    ~Strategy() {}
    virtual QString StrategyName() {return ""; }
    virtual QStringList getModel()  {return QStringList(); }
    virtual QStringList getBackground()  {return QStringList(); }
    virtual QStringList getModelFileNames()  {return QStringList(); }
    virtual QStringList getBackgroundFileNames()  {return QStringList(); }

    virtual Triple<double> FocalLenght()  {return Triple<double>(0,0,0); }
    virtual Triple<double> Diaphragm()  {return Triple<double>(0,0,0); }
    virtual Triple<double> ModelDistance()  {return Triple<double>(0,0,0); }
    virtual Triple<double> BackgroundDistance()  {return Triple<double>(0,0,0); }

protected:
    QStringList scanDirForFriendlyName(QString fileMask);
    QStringList scanDirForFileName(QString fileMask);
};

class Portrait: public Strategy{
    virtual QString StrategyName();
    virtual QStringList getModel();
    virtual QStringList getBackground();
    virtual QStringList getModelFileNames();
    virtual QStringList getBackgroundFileNames();

    virtual Triple<double> FocalLenght();
    virtual Triple<double> Diaphragm();
    virtual Triple<double> ModelDistance();
    virtual Triple<double> BackgroundDistance();
};

#endif // STRATEGIES_H
