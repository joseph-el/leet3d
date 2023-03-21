/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:18:46 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/03/21 21:36:50 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/**
 * @brief Parsing & Errors Codes
 */

# define MAP_KEY "01 NSEWDZK"
# define VALID_ "1DKZ "
# define ERR_MISSING "Missing something! "
# define ERR_KEY "Invalid Key! "
# define ERR_ARGS "Bad Argument! "
# define ERR_EXCT "The input file is missing the .cub extension! "
# define ERR_COLORS "Invalid Colors format! "
# define ERR_MAP "Invalid Map! "
# define ERR_POSITION "Invalid player position! "
# define ERR_DOOR "Invalid place for the door! "
# define ERR_PATH "Missing path of texture! "
# define INIT 16
# define CHECK 8
# define EXIT 32
# define NL 10
# define LAST 16
# define FIRST 4
# define SPACE 32
# define VERTICAL 14
# define HORIZONTAL 32
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define WHITE "\033[0;37m"

/**
 * @brief Sounds
 */

# define S_RUN "afplay ./sounds/run2.mp3"
# define S_SHOT "afplay ./sounds/shot.mp3 &"
# define S_CLICK "afplay ./sounds/click.mp3 &"
# define S_ODOOR "afplay ./sounds/odoor.mp3 &"
# define S_DAMAGE "afplay ./sounds/damage.mp3"
# define S_RELOAD "afplay ./sounds/reload.mp3 &"
# define S_OVER "afplay ./sounds/game_over.mp3 &"

# define S_SOUND4 "afplay ./sounds/music4.mp3 &"
# define S_SOUND1 "afplay ./sounds/music1.mp3 &"
# define S_SOUND2 "afplay ./sounds/music2.mp3 &"
# define S_SOUND3 "afplay ./sounds/music3.mp3 &"
# define S_ENEMY_SHOT "afplay ./sounds/enemy_shot.mp3"
# define MUTE "osascript -e \"set volume with output muted\""
# define UNMUTE "osascript -e \"set volume without output muted\""
# define UP "osascript -e \"set volume output volume (output volume of (get volume settings) + 10)\""
# define S_KILL "ps -ef | grep -E \"afplay | afplay | afplay afplay\" | awk \'{print $2}\' | xargs kill -9 2>/dev/null"
# define KILL_SOUND "ps -ef | grep -E \"music1.mp3\" | awk \'{print $2}\' | xargs kill -9 2>/dev/null ; " \
                    "ps -ef | grep -E \"music2.mp3\" | awk \'{print $2}\' | xargs kill -9 2>/dev/null ; " \
                    "ps -ef | grep -E \"music3.mp3\" | awk \'{print $2}\' | xargs kill -9 2>/dev/null ; " \
                    "ps -ef | grep -E \"music4.mp3\" | awk \'{print $2}\' | xargs kill -9 2>/dev/null ;" \

# define KILL_SHOT	"ps -ef | grep -E \"enemy_shot.mp3\" | awk \'{print $2}\' | xargs kill -9 2>/dev/null ; " \
                	"ps -ef | grep -E \"damage.mp3\" | awk \'{print $2}\' | xargs kill -9 2>/dev/null ;" \
	
# define DOWN "osascript -e \"set volume output volume (output volume of (get volume settings) - 10)\""

/**
 * @brief Raycasting 
 */

# define TILE_SIZE 64
# define NUM_RAYS 1280
# define MOVE_SPEED 20.0
# define ROTATE_SPEED 5.0
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define TEXTURE_DIMENTION 64
# define _MOVE_UP 4
# define _MOVE_DOWN 16
# define _MOVE_LEFT 64
# define _MOVE_RIGHT 32
# define ROTATE_LEFT 2
# define ROTATE_RIGHT 1
# define MINIMAP_H 200
# define MINIMAP_W 200
# define COLLISION 5
# define SCOPE 13
# define MX 500
# define MY 530

/**
 * @brief Events
 */

# define CNTRL 1
# define PAUSE 2
# define P_CNTRL 4
# define P_GAME 8
# define G_HOME 16
# define STARTING 1
# define INGANE 2
# define ERROR 1
# define FATAL 2
# define FREE_ZONE 4
# define SET_ENEMY 2
# define GUN_1 1
# define GUN_2 2
# define GUN_3 4
# define GUN_4 8
# define GUN_5 16
# define GUN_6 32
# define GUN_7 64
# define GUN_8 128
# define HEALT1 1
# define HEALT2 2
# define HEALT3 4
# define HEALT4 8
# define HEALT5 16
# define HEALT6 32

/**
 * @brief packagess (Paths | INDICES) 
 */

# define C_MAP1 "./packages/const_map/const_map1.cub"
# define C_MAP2 "./packages/const_map/const_map2.cub"
# define C_MAP3 "./packages/const_map/const_map3.cub"
# define C_MAP4 "./packages/const_map/const_map4.cub"

# define TEXTURES_PACKAGE "./packages/const_textures/t21.xpm\
							./packages/const_textures/t22.xpm\
							./packages/const_textures/t23.xpm\
							./packages/const_textures/t24.xpm\
							./packages/const_textures/t9.xpm\
							./packages/const_textures/t10.xpm\
							./packages/const_textures/t11.xpm\
							./packages/const_textures/t12.xpm\
							./packages/const_textures/t17.xpm\
							./packages/const_textures/t18.xpm\
							./packages/const_textures/t19.xpm\
							./packages/const_textures/t16.xpm\
							./packages/const_textures/t13.xpm\
							./packages/const_textures/t14.xpm\
							./packages/const_textures/t15.xpm\
							./packages/const_textures/t16.xpm"

# define CEIL_FLOR "./packages/const_textures/ceil3.xpm \
                    ./packages/const_textures/ceil2.xpm \
                    ./packages/const_textures/ceil.xpm \
                    ./packages/const_textures/ceil4.xpm " 

# define X_MAP1 14
# define Y_MAP1 6
# define X_MAP2 66
# define Y_MAP2 7
# define X_MAP3 40
# define Y_MAP3 13
# define X_MAP4 39
# define Y_MAP4 17

#endif