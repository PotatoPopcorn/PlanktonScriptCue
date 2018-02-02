#ifndef QUICKBUTTONPAGE_H
#define QUICKBUTTONPAGE_H


class QuickButtonPage
{
public:
    QuickButtonPage();
    bool getCueExists(int cue);

private:
    bool cueExists[10] = {false,false,false,false,false,false,false,false,false,false};
};

#endif // QUICKBUTTONPAGE_H
