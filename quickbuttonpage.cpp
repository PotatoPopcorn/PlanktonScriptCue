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

