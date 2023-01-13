#ifndef CLT_DEFS_H
#include "../_Imports.h"
#define CLT_DEFS_H
typedef struct client_info clt_inf;
typedef struct client_links* clt_lnk;
typedef struct client_links clt;
typedef struct sockaddr_in* sa_in;

struct client_info
{
    FILE*               file;
    int                 sock;
    int                 ID;
    char                GUID[37];
    struct sockaddr_in* addr;
};

struct client_links
{
    int     INDEX;
    clt_inf Client; 
    clt_lnk prev;
    clt_lnk next;
};

extern clt_lnk  CLT_LIST;
extern clt_lnk  NULL_CLIENT; 
extern clt_lnk  CURRENT_CLIENT;
extern int      CURRENT_INDEX;
extern int      INIS;
extern pthread_mutex_t CURRENT_INFO_MUTEX;

//Initialises the 
//Clients linked List
//Return :
// 0 -> Success
// -1-> Failure
extern int clt_inis();

/// @brief Creates new Client Structure 
/// @param Info Client Information (See struct client_info)
/// @return NULL : ERROR || clt_lnk : Pointer to new Client
extern clt_lnk clt_new( clt_inf Info);

/// @param Info Client Information (See struct client_info)

/// @brief Creates new Client Structure 
/// @param file 
/// @param sock 
/// @param ID 
/// @param ID 
/// @param Addr 
/// @return clt_inf : New Client info struct
extern clt_inf clt_inf_new(FILE* file, int sock, int ID, char* ID, sa_in Addr);


//Add a Client
//Returns:
//INTEGER -> index
//-1 -> Error Somewere
extern int clt_add(clt_inf New_Inf, clt_lnk* New_Client);
/*
//Check for past Connections
// Returns:
// -1-> Invalid
// 0 -> Correct
// 1 -> Incorrect

extern int clt_find_local_index(int index, clt_lnk* New_Client);
extern int clt_find_local_sock(int sock, clt_lnk* New_Client);
extern int clt_find_local_uuid(const char* UUID, clt_lnk* New_Client);
extern int clt_find_local_id(int ID, clt_lnk *New_Client);

//Deletion Functions
// Returns :
// 0 -> Success
// 1 -> User non-existant (Fail)

extern int clt_delete_runtime_findex(int index);
extern int clt_delete_runtime_fsock(int sock);
extern int clt_delete_runtime_fuuid(const char* UUID);
extern int clt_delete_runtime_fid(int ID);

//Case of Reconnection
//Returns:
// 0 -> Success
// 1 -> Client non-existant
//////// FIx here GIVE ALL to-be-updates values (NULL them if you dont want to change), search using ###### /////
extern int clt_update_runtime_findex(const int* sock, const char* UUID, const int* ID, int INDEX);
extern int clt_update_runtime_fsock(const char* UUID, const int* ID, int sock);
//NotYet 
/*
extern int clt_update_runtime_fthread(const int* sock, const char* UUID, const int* ID, int INDEX);
*/

#endif