#ifndef H_SERVER
#define H_SERVER

#include <stdlib.h>
#include <string.h>
#include <uv.h>

#define DEFAULT_PORT 8080
#define DEFAULT_BACKLOG 128

uv_loop_t *loop;
struct sockaddr_in addr;

typedef struct {
    uv_write_t req;
    uv_buf_t buf;
} write_req_t;

void free_write_req(uv_write_t *req);

void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf);

void on_close(uv_handle_t* handle);

void echo_write(uv_write_t *req, int status);

void echo_read(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf);

void on_new_connection(uv_stream_t *server, int status);

int run_uv_server();
#endif
