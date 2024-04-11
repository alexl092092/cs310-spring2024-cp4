#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <stdlib.h>
using namespace std;

class Song {
	public:
		Song(unsigned int, string, unsigned int, string);
		Song();
	
		unsigned int getSongId() ;
		string getArtistName() ;
		unsigned int getSongDuration() ;
		string getSongTitle();
		
	private:
		unsigned int songId;
		string artistName;
		unsigned int songDuration;
		string songTitle;
};

#endif
