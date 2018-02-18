#include "quickbuttonpage.h"

QuickButtonPage::QuickButtonPage()
{

}

bool QuickButtonPage::getCueExists(int cue)
{
    return cueExists[cue];
}

BaseCue* QuickButtonPage::getCue(int cue)
{
    return cueArr[cue];
}

void QuickButtonPage::setCue(BaseCue *cuePtr, int cueNum)
{
    cueArr[cueNum] = cuePtr;
    cueExists[cueNum] = true;
}

void QuickButtonPage::removeCue(int cue)
{
    cueExists[cue] = false;
}

void QuickButtonPage::clearPage()
{
    for(int i = 0; i < 10; i++)
    {
        removeCue(i);
    }
}

QJsonObject QuickButtonPage::save()
{
    QJsonObject cueJson;
    QJsonArray cueArray;
    for(int i = 0; i < 10; i++)
    {
        QJsonObject currentCue;
        if(!getCueExists(i)){
            currentCue["exists"] = false;
        }
        else
        {
            currentCue = getCue(i)->save();
            currentCue["exists"] = true;
        }
        cueArray.append(currentCue);
    }
    cueJson["cues"] = cueArray;
    return cueJson;
}

void QuickButtonPage::load(QJsonObject data)
{
    QJsonArray cueArray = data["cues"].toArray();
    for(int i = 0; i < cueArray.size(); i++)
    {
        QJsonObject currentCue = cueArray.at(i).toObject();
        if(!currentCue["exists"].toBool())
        {
            qDebug() << "Cue " << i << "doesn't exist";
            continue;
        }
        qDebug() << "Cue " << i << "exists";
        BaseCue *nextCue = new BaseCue();
        nextCue->load(currentCue);
        setCue(nextCue, i);
    }
}



