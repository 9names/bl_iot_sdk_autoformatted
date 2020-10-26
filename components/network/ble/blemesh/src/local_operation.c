/*  Bluetooth Mesh */

#include <errno.h>
#include <string.h>

#include "access.h"
#include "crypto.h"
#include "foundation.h"
#include "include/main.h"
#include "lpn.h"
#include "mesh.h"
#include "mesh_settings.h"
#include "transport.h"

int bt_mesh_model_subscribe_group_addr(u16_t elem_addr, u16_t cid, u16_t mod_id,
                                       u16_t group_addr) {
  return -ENOMEM;
}

int bt_mesh_model_unsubscribe_group_addr(u16_t elem_addr, u16_t cid,
                                         u16_t mod_id, u16_t group_addr) {
  return -ENODEV;
}
