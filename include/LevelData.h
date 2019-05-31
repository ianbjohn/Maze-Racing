#ifndef LEVELDATA_H_INCLUDED
#define LEVELDATA_H_INCLUDED

#define NUM_LEVELS 8

//structure of arrays :)
struct LevelData
{
    int width[NUM_LEVELS];  //levels are all the same height
    const unsigned char* tiles[NUM_LEVELS];
};


extern const struct LevelData levels;

extern const unsigned char level0[278];
extern const unsigned char level1[358];
extern const unsigned char level2[314];
extern const unsigned char level3[122];
extern const unsigned char level4[326];
extern const unsigned char level5[246];
extern const unsigned char level6[318];
extern const unsigned char level7[262];

#endif // LEVELDATA_H_INCLUDED
