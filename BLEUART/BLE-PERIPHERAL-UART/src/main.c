/* @authors

Derek Nielsen Araújo Alves
João Pedro Brito Tomé
Matheus Ferreira Gêda
Ruan Heleno Correa da Silva

Universidade Federal de Alagoas
Intituto de Computação
Engenharia de Computação
*/


#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <zephyr/types.h>
#include <sys/printk.h>
#include <sys/byteorder.h>
#include <zephyr.h>
#include <kernel.h>
#include <services/ble_application.h>
#include <services/ble_uart_service.h>

static void on_ble_rx_data(const uint8_t *buffer, size_t len) {
    service_transmit(buffer, len);
}

static void on_ble_stack_ready(struct bt_conn *conn) {
    (void)conn;
    service_register(on_ble_rx_data);
}

void main (void) {
    ble_application_start(on_ble_stack_ready);
}