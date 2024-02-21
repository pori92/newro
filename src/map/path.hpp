// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef PATH_HPP
#define PATH_HPP

#include <common/cbasetypes.hpp>
#include "map.hpp"

enum cell_chk : uint8;

#define MOVE_COST 10
#define MOVE_DIAGONAL_COST 14

#define MAX_WALKPATH 32

enum directions : int8 {
	DIR_CENTER = -1,
	DIR_NORTH = 0,
	DIR_NORTHWEST = 1,
	DIR_WEST = 2,
	DIR_SOUTHWEST = 3,
	DIR_SOUTH = 4,
	DIR_SOUTHEAST = 5,
	DIR_EAST = 6,
	DIR_NORTHEAST = 7,
	DIR_MAX
};

struct walkpath_data {
	unsigned char path_len,path_pos;
	enum directions path[MAX_WALKPATH];
};

struct shootpath_data {
	int rx,ry,len;
	int x[MAX_WALKPATH];
	int y[MAX_WALKPATH];
};

#define check_distance_bl(bl1, bl2, distance) check_distance((bl1)->x - (bl2)->x, (bl1)->y - (bl2)->y, distance)
#define check_distance_blxy(bl, x1, y1, distance) check_distance((bl)->x-(x1), (bl)->y-(y1), distance)
#define check_distance_xy(x0, y0, x1, y1, distance) check_distance((x0)-(x1), (y0)-(y1), distance)

#define distance_bl(bl1, bl2) distance((bl1)->x - (bl2)->x, (bl1)->y - (bl2)->y)
#define distance_blxy(bl, x1, y1) distance((bl)->x-(x1), (bl)->y-(y1))
#define distance_xy(x0, y0, x1, y1) distance((x0)-(x1), (y0)-(y1))

#define check_distance_client_bl(bl1, bl2, distance) check_distance_client((bl1)->x - (bl2)->x, (bl1)->y - (bl2)->y, distance)
#define check_distance_client_blxy(bl, x1, y1, distance) check_distance_client((bl)->x-(x1), (bl)->y-(y1), distance)
#define check_distance_client_xy(x0, y0, x1, y1, distance) check_distance_client((x0)-(x1), (y0)-(y1), distance)

#define distance_client_bl(bl1, bl2) distance_client((bl1)->x - (bl2)->x, (bl1)->y - (bl2)->y)
#define distance_client_blxy(bl, x1, y1) distance_client((bl)->x-(x1), (bl)->y-(y1))
#define distance_client_xy(x0, y0, x1, y1) distance_client((x0)-(x1), (y0)-(y1))

// calculates destination cell for knockback
int path_blownpos(int16 m,int16 x0,int16 y0,int16 dx,int16 dy,int count);

// tries to find a walkable path
bool path_search(struct walkpath_data *wpd,int16 m,int16 x0,int16 y0,int16 x1,int16 y1,int flag,cell_chk cell);

// tries to find a shootable path
bool path_search_long(struct shootpath_data *spd,int16 m,int16 x0,int16 y0,int16 x1,int16 y1,cell_chk cell);

// distance related functions
bool check_distance(int dx, int dy, int distance);
unsigned int distance(int dx, int dy);
bool check_distance_client(int dx, int dy, int distance);
int distance_client(int dx, int dy);

bool direction_diagonal( enum directions direction );
bool direction_opposite( enum directions direction );

/// A* Related
/// @name Structures and defines for A* pathfinding
/// @{

#define SET_OPEN 0
#define SET_CLOSED 1

#define PATH_DIR_NORTH 1
#define PATH_DIR_WEST 2
#define PATH_DIR_SOUTH 4
#define PATH_DIR_EAST 8

/// Estimates the cost from (x0,y0) to (x1,y1).
/// This is inadmissible (overestimating) heuristic used by game client.
#define heuristic(x0, y0, x1, y1)	(MOVE_COST * (abs((x1) - (x0)) + abs((y1) - (y0)))) // Manhattan distance
/// @}

// Translates dx,dy into walking direction
static enum directions walk_choices [3][3] =
{
	{DIR_NORTHWEST,DIR_NORTH,DIR_NORTHEAST},
	{DIR_WEST,DIR_CENTER,DIR_EAST},
	{DIR_SOUTHWEST,DIR_SOUTH,DIR_SOUTHEAST},
};

struct path_node {
	struct path_node* parent; ///< pointer to parent (for path reconstruction)
	short x; ///< X-coordinate
	short y; ///< Y-coordinate
	short g_cost; ///< Actual cost from start to this node
	short f_cost; ///< g_cost + heuristic(this, goal)
	short flag; ///< SET_OPEN / SET_CLOSED
};

auto heap_comp = [](const path_node* a, const path_node* b) { return b->f_cost < a->f_cost; };

class open_heap {
private:
	std::vector<path_node*> open_set;
	std::unordered_map<path_node*, size_t> index;

public:

	// Push the node to 'open' set
	void push(path_node* node) {
		open_set.push_back(node);
		std::push_heap(open_set.begin(), open_set.end(), heap_comp);
		index[node] = open_set.size() - 1;
	}

	// Move top element to back of heap
	void pop_heap() {
		std::pop_heap(open_set.begin(), open_set.end(), heap_comp);
		pop_index(); // Update index
	}

	// Erase back of heap and index
	void pop_back() {
		index.erase(open_set.back()); // Remove from index
		open_set.pop_back();
	}

	// Clearing the heap and index
	void clear(){
		open_set.clear();
		index.clear();		
	}

	// Function to get node index
	size_t get_index(path_node* node) const {
		auto it = index.find(node);
		if (it != index.end() && it->second < open_set.size()) 
			return it->second;
		return -1; // Not found
	}

	// Update 'open' node with an higher cost than this node
	bool update_node(path_node* node){
		size_t i = get_index(node);
		if( i < 0)
			return true; // throw path cant be reached
		erase(i);
		push(node);
		return false;
	}

	// Erase node at [i] positison on the 'open' set
	void erase(size_t i) {
		sift_up(i);
		pop_back(); // Remove the last element
	}

	bool empty() const {
		return open_set.empty();
	}

	path_node* back() const {
		return open_set.back();
	}

	// Perform a sift up
	void sift_up(size_t i) {
		while (i > 0 && heap_comp(open_set[i], open_set[(i - 1) / 2])) {
			std::swap(open_set[i], open_set[(i - 1) / 2]);
			index[open_set[i]] = i;
			index[open_set[(i - 1) / 2]] = (i - 1) / 2;
			i = (i - 1) / 2;
		}
	}

	// Pop the indexes
	void pop_index() {
		for(auto& it : open_set)
			index[it]--;
		index[open_set.back()] = open_set.size() - 1;
	}
};
/// @}

//
void do_init_path();
void do_final_path();

#endif /* PATH_HPP */
