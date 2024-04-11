#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Song.h"
using namespace std;

struct Playlist {
	int pId;
	string pName;
	Song* pSongs;
	int size;
	int capacity;
	
	Playlist();
	~Playlist();
	
	Playlist(const Playlist &o);
	Playlist& operator=(const Playlist &o);
};	

class SongCollection {
	public:
		SongCollection();
		~SongCollection();
		SongCollection(const SongCollection &c);
		SongCollection& operator=(const SongCollection &c);
		
		void growArray();
		
		void createSong(Song song);
		void removeSong(int songId);
		void createPlaylist(int playlistId, string playlistName);
		void addSongToPlaylist(int songId, int playlistId);
		void removeSongFromPlaylist(int songId, int playlistId);
		
		void seeSong(int songId);
		void seePlaylist(int playlistId);

		void deletePlaylist(int playlistId);
		void copyPlaylist(int playlistId, int newPlaylistId, string newPlaylistName);
		void renamePlaylist(int playlistId, string newPlaylistName);
	
	private:
		Song* createdSongs;
		
		int capacity;
		int size;
		int playlistId;
		string playlistName;
		vector<Playlist*> playlists;
		
		Song* pSongs;
		
};

#endif
