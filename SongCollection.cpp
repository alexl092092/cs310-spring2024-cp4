#include "SongCollection.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
using namespace std;

Playlist::Playlist()
{
	pId = -1;
	pName = "";
	size = 0;
	capacity = 1;
	pSongs = new Song[capacity];
}

Playlist::~Playlist()
{
	delete[] pSongs;
}

Playlist::Playlist(const Playlist &o) : capacity(o.capacity), size(o.size), pName(o.pName), pId(o.pId)
{
	delete[] pSongs;
	pSongs = new Song[capacity];
	copy(o.pSongs, o.pSongs + size, pSongs);
}

Playlist& Playlist::operator=(const Playlist &o)
	{
		if (this!= &o)
		{
			delete[] pSongs;
			pId = o.pId;
			pName = o.pName;
			size = o.size;
			capacity = o.capacity;
			pSongs = new Song[capacity];
			copy(o.pSongs, o.pSongs + size, pSongs);
			
		}
	return *this;
	}
SongCollection::SongCollection() 
{
	capacity = 1;
	size = 0;
	createdSongs = new Song[capacity];
}

SongCollection::~SongCollection()
{
	delete[] createdSongs;
}

SongCollection::SongCollection(const SongCollection &c) : capacity(c.capacity), size(c.size)
{
	delete[] createdSongs;
	createdSongs = new Song[capacity];
	copy(c.createdSongs, c.createdSongs + size, createdSongs);
}

SongCollection& SongCollection::operator=(const SongCollection &c)
{
	if (this!= &c)
	{
		delete[] createdSongs;
		createdSongs = new Song[capacity];
		copy(c.createdSongs, c.createdSongs + size, createdSongs);
		size = c.size;
		capacity = c.capacity;
	}
	return *this;
}

void SongCollection::growArray()
{
	capacity*=2;
	Song* newSongs = new Song[capacity];

	for (int i = 0; i < size; i++)
	{
		newSongs[i] = createdSongs[i];
	}
	delete[] createdSongs;
	createdSongs = newSongs;
}

void SongCollection::createSong(Song song)
{
	int minutes = 0;
	int seconds = 0;
	if (size == capacity)
	{
		growArray();
	}
	int same = 0;
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (createdSongs[i].getSongId() == song.getSongId())
			{
				cout << "song id " << song.getSongId() << " already used for " << createdSongs[i].getSongTitle() << " by " << createdSongs[i].getArtistName() << endl;
				same++;
				break;
			}
		}
		if (same == 0)
		{
			minutes = song.getSongDuration() / 60;
			seconds = song.getSongDuration() % 60; 
			cout << "new song " << song.getSongId() << " " << song.getSongTitle() << " by "  << song.getArtistName() << " " << minutes << ":" << setw(2) << right << setfill('0') << seconds << endl;
			createdSongs[size] = song;
			size++;
		}
	}
	else
	{
		minutes = song.getSongDuration() / 60;
		seconds = song.getSongDuration() % 60; 
		cout << "new song " << song.getSongId() << " " << song.getSongTitle() << " by "  << song.getArtistName() << " " << minutes << ":" << setw(2) << right << setfill('0') << seconds << endl;
		createdSongs[size] = song;
		size++;
	}
}

void SongCollection::removeSong(int songId)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (createdSongs[i].getSongId() == songId)
		{
			index = i;
			//cout << index << endl;
		}
	}
	if (index == -1)
	{
		cout << "song " << songId << " not found" << endl;
		return;
	}
	else 
	{
	
       		for (int i = 0; i < playlists.size(); i++)
       		{
      		      for (int j = 0; j < playlists[i]->size; j++) 
      		      {
      		      		if (playlists[i]->pSongs[j].getSongId() == songId) 
      		    		{
                			for (int k = j; k < playlists[i]->size - 1; k++) 
                			{
                       				playlists[i]->pSongs[k] = playlists[i]->pSongs[k + 1];
                    			}
                  			playlists[i]->size--;
                    			break; 
                    		}
                    	}
                }
                
        }
	if (size < 2 || size == index)
	{
		cout << "song " << songId << ", " << createdSongs[index].getSongTitle() << " by " << createdSongs[index].getArtistName() << ", removed" << endl;
		size--;
	}
	else
	{
		cout << "song " << songId << ", " << createdSongs[index].getSongTitle() << " by " << createdSongs[index].getArtistName() << ", removed" << endl;
		for (int i = index; i < size - 1; i++)
		{
			createdSongs[i] = createdSongs[i+1];
		}
		size--;
	}
	
/*	cout << "Size: " << size << ", Capacity: " << capacity << endl;
	int minutes = 0;
	int seconds = 0;
	
	for (int i = 0; i < size; i++)
	{
		minutes = createdSongs[i].getSongDuration() / 60;
		seconds = createdSongs[i].getSongDuration() % 60; 
		cout << createdSongs[i].getSongId() << " " << createdSongs[i].getSongTitle() << " by "  << createdSongs[i].getArtistName() << " " << minutes << ":" << setw(2) << right << setfill('0') << seconds << endl;
	}
	*/

}

void SongCollection::createPlaylist(int playlistId, string playlistName)
{
	int found = 0;
	for (int i = 0; i < playlists.size(); i++)
	{
		if ( playlists[i]->pId == playlistId)
		{
			cout << "playlist id " << playlistId << " already used for " << playlists.at(i)->pName << endl;
			found = 1;
		}
	}

	if (found != 1)
	{

		Playlist* newPlaylist = new Playlist();
		delete[] newPlaylist->pSongs;
		newPlaylist->pId = playlistId;
		newPlaylist->pName = playlistName;
		newPlaylist->capacity;
		newPlaylist->size;
		newPlaylist->pSongs = new Song[capacity];
		
		playlists.push_back(newPlaylist);
//		delete newPlaylist;
//		delete[] newPlaylist->pSongs;
		cout << "new playlist " << playlistId << " called " << playlistName << endl; 
		
	}
	
}

void SongCollection::addSongToPlaylist(int songId, int playlistId)
{

	int playlistExists = 0;
	int songExists = 0;
	int songinplaylist = 0;
	int playlistIndex = 0;
	int songIndex = 0;
	
	for (int i = 0; i < playlists.size(); i++)
	{
		if ( playlists[i]->pId == playlistId)
		{

			playlistExists = 1;
			playlistIndex = i;
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (createdSongs[i].getSongId() == songId )
		{
			songExists = 1;
			songIndex = i;
			break;
		}
	}
	if (songExists == 0)
	{
		cout << "song " << songId << " does not exist" << endl;
		return;
	}
	
	if (playlistExists == 0)
	{
		cout << "playlist " << playlistId << " does not exist" << endl;
		return;
	}
	for (int i = 0; i < playlists[playlistIndex]->size; i++)
	{
		if (playlists[playlistIndex]->pSongs[i].getSongId() == songId)
		{
			cout << "song is already in playlist" << endl;
			songinplaylist = 1;
			break;
		}
	}
	
	if (songinplaylist == 0)
	{
		if (playlists[playlistIndex]->size == playlists[playlistIndex]->capacity)
		{
			playlists[playlistIndex]->capacity *=2;
			Song* newSongs = new Song[playlists[playlistIndex]->capacity];

			for (int i = 0; i < playlists[playlistIndex]->size; i++)
			{
				newSongs[i] = playlists[playlistIndex]->pSongs[i];
			}
			delete[] playlists[playlistIndex]->pSongs;
			playlists[playlistIndex]->pSongs = newSongs;
		}

		playlists[playlistIndex]->pSongs[playlists[playlistIndex]->size++] = createdSongs[songIndex];
		cout << "song " << songId << " successfully added to playlist " << playlistId << endl;
	}
	
	/*
	int minutes = 0;
	int seconds = 0;
	cout << "Size: " << playlists[playlistIndex].size << ", Capacity: " << playlists[playlistIndex].capacity << endl;
	for (int i = 0; i < playlists[playlistIndex].size; i++)
	{
		Song currentSong = playlists[playlistIndex]->pSongs[i];
		minutes = currentSong.getSongDuration() / 60;
		seconds = currentSong.getSongDuration() % 60; 
		cout << currentSong.getSongId() << " " << currentSong.getSongTitle() << " by "  << currentSong.getArtistName() << " " << minutes << ":" << setw(2) << right << setfill('0') << seconds << endl;
	}
	*/
}

void SongCollection::removeSongFromPlaylist(int songId, int playlistId)
{
	
	int playlistExists = 0;
	int songExists = 0;
	int songinplaylist = 0;
	int playlistIndex = 0;
	int index = 0;
	
	for (int i = 0; i < playlists.size(); i++)
	{
		if ( playlists[i]->pId == playlistId)
		{
			playlistExists = 1;
			playlistIndex = i;
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (createdSongs[i].getSongId() == songId )
		{
			songExists = 1;
			break;
		}
	}
	if (songExists == 0)
	{
		cout << "song " << songId << " does not exist" << endl;
		return;
	}
	
	if (playlistExists == 0)
	{
		cout << "playlist " << playlistId << " does not exist" << endl;
		return;
	}
	
	
	for (int i = 0; i < playlists[playlistIndex]->size; i++)
	{
		if (playlists[playlistIndex]->pSongs[i].getSongId() == songId)
		{
			songinplaylist = 1;
			index = i;
			break;
		}
	}
	
	if (playlists[playlistIndex]->size < 2 || playlists[playlistIndex]->size == index)
	{
		cout << "song " << songId << " successfully removed from playlist " << playlistId << endl;
		playlists[playlistIndex]->size--;
		
	}
	else if (songinplaylist == 1)
	{
		for (int j = index; j < playlists[playlistIndex]->size - 1; j++)
		{
			playlists[playlistIndex]->pSongs[j] = playlists[playlistIndex]->pSongs[j+1]; 
		}
		playlists[playlistIndex]->size--;
		cout << "song " << songId << " successfully removed from playlist " << playlistId << endl;
	}
	else
	{
		cout << "song " << songId << " is not in playlist " << playlistId << endl;
	}
	
	
/*	int minutes = 0;
	int seconds = 0;
	cout << "Size: " << playlists[playlistIndex].size << ", Capacity: " << playlists[playlistIndex].capacity << endl;
	for (int i = 0; i < playlists[playlistIndex].size; i++)
	{
		Song currentSong = playlists[playlistIndex]->pSongs[i];
		minutes = currentSong.getSongDuration() / 60;
		seconds = currentSong.getSongDuration() % 60; 
		cout << currentSong.getSongId() << " " << currentSong.getSongTitle() << " by "  << currentSong.getArtistName() << " " << minutes << ":" << setw(2) << right << setfill('0') << seconds << endl;
	} */
}

void SongCollection::seeSong(int songId)
{	
	int songExists = 0;
	int songIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (createdSongs[i].getSongId() == songId )
		{
			songExists = 1;
			songIndex = i;
			break;
		}
	}
	if (songExists == 0)
	{
		cout << "song " << songId << " does not exist" << endl;
	}
	else
	{
		cout << createdSongs[songIndex].getSongId() << " " << createdSongs[songIndex].getSongTitle() << " by "  << createdSongs[songIndex].getArtistName() << endl;
	}
}
void SongCollection::seePlaylist(int playlistId)
{
	int playlistExists = 0;
	int playlistIndex = 0;
	for (int i = 0; i < playlists.size(); i++)
	{
		if ( playlists[i]->pId == playlistId)
		{
			playlistExists = 1;
			playlistIndex = i;
			break;
		}
	}

	if (playlistExists == 0)
	{
		cout << "playlist " << playlistId << " does not exist" << endl;
		return;
	}
	cout << "Songs in playlist " << playlistId << " " << playlists[playlistIndex]->pName << endl;
        if (playlists[playlistIndex]->size == 0)
	{
		cout << "playlist has no songs" << endl;
		return;
	}
	else if (playlists[playlistIndex]->size == 1)
	{
		Song currentSong = playlists[playlistIndex]->pSongs[0];
		cout << currentSong.getSongId() << " " << currentSong.getSongTitle() << " by "  << currentSong.getArtistName() << endl;
	}
	
	else
	{
	
		for (int i = 0; i < playlists[playlistIndex]->size - 1; i++)
		{
			for (int j = 0; j < playlists[playlistIndex]->size - i - 1; j++)
			{
				if (playlists[playlistIndex]->pSongs[j].getSongId() > playlists[playlistIndex]->pSongs[j + 1].getSongId())
				{
					swap(playlists[playlistIndex]->pSongs[j], playlists[playlistIndex]->pSongs[j+1]);
				}
			}
		}
		
		for (int i = 0; i < playlists[playlistIndex]->size; i++)
		{
			Song currentSong = playlists[playlistIndex]->pSongs[i];
			cout << currentSong.getSongId() << " " << currentSong.getSongTitle() << " by "  << currentSong.getArtistName() << endl;
		}
	}
//	delete[] playlists[playlistIndex]->pSongs;
}


void SongCollection::deletePlaylist(int playlistId)
{
	int playlistExists = 0;
	int playlistIndex = 0;
	for (int i = 0; i < playlists.size(); i++)
	{
		if ( playlists[i]->pId == playlistId)
		{
			playlistExists = 1;
			playlistIndex = i;
			break;
		}
	}
	if (playlistExists == 0)
	{
		cout << "playlist " << playlistId << " does not exist" << endl;
	}
	else
	{
		
		delete[] playlists[playlistIndex]->pSongs;
		playlists.erase(playlists.begin() + playlistIndex);
		cout << "playlist " << playlistId << " successfully deleted" << endl;
	}
}
void SongCollection::copyPlaylist(int playlistId, int newPlaylistId, string newPlaylistName)
{
	int playlistExists = 0;
	int playlistIndex = 0;
	for (int i = 0; i < playlists.size(); i++)
	{
		if ( playlists[i]->pId == playlistId)
		{
			playlistExists = 1;
			playlistIndex = i;
			break;
		}
	}
	if (playlistExists == 0)
	{
		cout << "playlist " << playlistId << " does not exist" << endl;
		return;
	}
	
	for (int i = 0; i < playlists.size(); i++)
	{
		if (playlists[i]->pId == newPlaylistId)
		{
			cout << "playlist id " << newPlaylistId << " already used for " << playlists[i]->pName << endl;
			return;
		}
	}
	Playlist* newPlaylist = new Playlist;
	delete[] newPlaylist->pSongs;
	newPlaylist->pId = newPlaylistId;
	newPlaylist->pName = newPlaylistName;
	newPlaylist->capacity = playlists[playlistIndex]->capacity;
	newPlaylist->size = playlists[playlistIndex]->size;
	newPlaylist->pSongs = new Song[newPlaylist->capacity];
	
	for (int i = 0; i < playlists[playlistIndex]->size; i++)
	{
		newPlaylist->pSongs[i] = playlists[playlistIndex]->pSongs[i];
	}
	
	playlists.push_back(newPlaylist);
//	delete newPlaylist;

	cout << "playlist " << playlistId << " successfully copied to playlist " << newPlaylistId << " called " << newPlaylistName << endl; 
	
}
void SongCollection::renamePlaylist(int playlistId, string newPlaylistName)
{
	int playlistExists = 0;
	int playlistIndex = 0;
	for (int i = 0; i < playlists.size(); i++)
	{
		if ( playlists[i]->pId == playlistId)
		{
			playlistExists = 1;
			playlistIndex = i;
			break;
		}
	}
	if (playlistExists == 0)
	{
		cout << "playlist " << playlistId << " does not exist" << endl;
		return;
	}
	
	playlists[playlistIndex]->pName = newPlaylistName;
	cout << "playlist " << playlistId << " name successfully changed to " << newPlaylistName << endl;

}
