#include <iostream>
#include <stdlib.h>
#include "Song.h"
using namespace std;

Song::Song(unsigned int sId, string artist, unsigned int duration, string title) : songId(sId), artistName(artist), songDuration(duration), songTitle(title)
{}


Song::Song() : songId(0), artistName(""), songDuration(0), songTitle("")
{}

unsigned int Song::getSongId()
{
	return songId;
}

string Song::getArtistName() 
{
	return artistName;
}

unsigned int Song::getSongDuration() 
{
	return songDuration;
}


string Song::getSongTitle()
{
	return songTitle;
}

