package main

import (
	"fmt"
	"net/http"
)

func main() {
	//1. defined the handler function which whill handle our request
	http.HandleFunc("/test-server", func(rw http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(rw, "\nThis is a test server\n")
	})
	//2. Listen on a specific port
	http.ListenAndServe(":80", nil)
}
