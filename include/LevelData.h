#ifndef LEVELDATA_H_INCLUDED
#define LEVELDATA_H_INCLUDED

#define NUM_LEVELS 2

//structure of arrays :)
struct LevelData
{
    int width[NUM_LEVELS];  //levels are all the same height
    const unsigned char* tiles[NUM_LEVELS];
};


extern const struct LevelData levels;

extern const unsigned char level0[278];
extern const unsigned char level1[358];


#endif // LEVELDATA_H_INCLUDED
