# List of client scenario code

## Default settings
* **readwait=0; :** If >0 delay the reading in an other thread with a sleep(readwait)
* **shutdown_done=false; :** Indicate that the shutdown has be done
* **close_after_read=false; :** Indicate to wait to read the data before closing the socket
* **use_shutdown=false; :** Use shutdown to close the socket on receiving EPOLLRDHUP event
* **connected=false; :** Indicate the socket is connected 
* **not_closing_on_close_detected=false; :** Not close the socket on EPOLLRDHUP event
* **close_after_connect=false; :** Close the connection after the connect return
## 0 : Default Settings
