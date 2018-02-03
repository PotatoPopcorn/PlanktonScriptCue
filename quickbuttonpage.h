#ifndef QUICKBUTTONPAGE_H
#define QUICKBUTTONPAGE_H

#include "basecue.h"

class QuickButtonPage
{
public:
    QuickButtonPage();
    bool getCueExists(int cue);
    BaseCue* getCue(int cue);
    void setCue(BaseCue* cuePtr, int cueNum);
    void removeCue(int cue);

private:
    bool cueExists[10] = {false,false,false,false,false,false,false,false,false,false};
    BaseCue *cueArr[10];
};

#endif // QUICKBUTTONPAGE_H
