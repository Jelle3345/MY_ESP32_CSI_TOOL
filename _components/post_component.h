//
// Created by jelle on 07/06/2023.
//
#include <stdio.h>
#include <string.h>
#include <esp_http_client.h>


void send_post_request(const char *data) {
    esp_http_client_config_t config = {
            .url = "http://192.168.4.2:80",
            .timeout_ms = 1000, // to keep going after the post fails
            .keep_alive_enable = false,  // not sure if needed
    };
    esp_http_client_handle_t client = esp_http_client_init(&config);

    esp_http_client_set_method(client, HTTP_METHOD_POST);
    esp_http_client_set_post_field(client, data, strlen(data));

    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        printf("POST request sent successfully\n");
    } else {
        printf("Failed to send POST request\n");
    }

    esp_http_client_cleanup(client);
}
