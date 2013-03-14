/*
 ============================================================================
 Name        : eventdemo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <event.h>
#include <evhttp.h>
#include <stdlib.h>
#include <unistd.h>


struct http_client {
    struct evhttp_connection *conn;
    struct evhttp_request *req;
    int finished;
};

void _reqhandler(struct evhttp_request *req, void *state) {
    struct http_client *hc = (struct http_client*)state;
    hc->finished = 1;

    if (req == NULL) {
        printf("timed out!\n");
    } else if (req->response_code == 0) {
        printf("connection refused!\n");
    } else if (req->response_code != 200) {
        printf("error: %u %s\n", req->response_code, req->response_code_line);
    } else {
       printf("success: %u %s\n", req->response_code, req->response_code_line);
       size_t len = evbuffer_get_length(req->input_buffer);
       char data[len];
       evbuffer_remove(req->input_buffer,data,len);
       printf("thd result %s\n",data);
    }
    event_loopexit(NULL);
}

void timeout_cb(int fd, short event, void *arg) {
    struct http_client *hc = (struct http_client*)arg;
    printf("Timed out\n");

    if (hc->finished == 0){ // Can't cancel request if the callback has already executed
        evhttp_cancel_request(hc->req);
    }
}
/*
int main(int argc, char *argv[]) {
    struct http_client *hc = (struct http_client *)malloc(sizeof(struct http_client));
    hc->finished = 0;

    struct event ev;
    struct timeval tv;

    tv.tv_sec = 3; // Timeout is set to 3.005 seconds
    tv.tv_usec = 5000;


    const char *addr = "173.194.39.64"; //google.com
    unsigned int port = 80;

    event_init();

    hc->conn = evhttp_connection_new(addr, port);
    evhttp_connection_set_timeout(hc->conn, 5);

    hc->req = evhttp_request_new(_reqhandler, (void*)hc);
    evhttp_add_header(hc->req->output_headers, "Host", addr);
    evhttp_add_header(hc->req->output_headers, "Content-Length", "0");
    evhttp_make_request(hc->conn, hc->req, EVHTTP_REQ_GET, "/");

    evtimer_set(&ev, timeout_cb, (void*)hc); // Set a timer to cancel the request after certain time
    evtimer_add(&ev, &tv);

    printf("starting event loop..\n");
    printf("\n");
    event_dispatch();

    //clean the resources
    printf("now here");
   // event_free(&ev);
    return 0;
}
*/
