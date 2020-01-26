/*
 * hid_device_drivers.h
 *
 * Created on: Jan 4, 2020
 * Author: Pragun Goyal
 */

#include <mmo_mouse_hid_driver.hpp>
#include "usbh_hid.hpp"
#include "logitech_g600.hpp"

extern uint8_t PrintHexBuf(uint8_t *buff, uint8_t len);

#define KEYBOARD_INTERFACE 1
#define MOUSE_INTERFACE 0

//The following are not used (for now)
#define KEYBOARD_REPORT_DESCRIPTOR_BUFFER_SIZE 135
#define MOUSE_REPORT_DESCRIPTOR_BUFFER_SIZE 67
#define KEYBOARD_REPORT_BUFFER 32
#define MOUSE_REPORT_BUFFER 9

Logitech_G600_Mouse_Driver::Logitech_G600_Mouse_Driver(): MMO_Mouse_HID_Driver(
		(uint8_t) KEYBOARD_INTERFACE,
		(uint8_t) MOUSE_INTERFACE)
{
	printf("Constructing Logitech G600 Driver Object\r\n");
}

Logitech_G600_Mouse_Driver::~Logitech_G600_Mouse_Driver(){};

USBH_StatusTypeDef Logitech_G600_Mouse_Driver::hid_handle_init(HID_HandleTypeDef *hid_handle){
	hid_handle->report_buffer = (uint8_t*) malloc(hid_handle->length);
	printf("Logitech G600 Mouse Initialized.\r\n");
	return USBH_OK;
}

USBH_StatusTypeDef Logitech_G600_Mouse_Driver::process_hid_report_descriptor_mouse(uint8_t *buff, uint8_t len){
	printf("Mouse received report descriptor: %d bytes\r\n", len);
	PrintHexBuf(buff, len);
	return USBH_OK;
}

USBH_StatusTypeDef Logitech_G600_Mouse_Driver::process_hid_report_descriptor_keyboard(uint8_t *buff, uint8_t len){
	printf("Keyboard received report descriptor: %d bytes\r\n", len);
	PrintHexBuf(buff, len);
	return USBH_OK;
}

USBH_StatusTypeDef Logitech_G600_Mouse_Driver::process_hid_report_mouse (uint8_t *buff, uint8_t len){
	printf("Mouse received report: %d bytes\r\n", len);
	PrintHexBuf(buff, len);
	return USBH_OK;
}

USBH_StatusTypeDef Logitech_G600_Mouse_Driver::process_hid_report_keyboard (uint8_t *buff, uint8_t len){
	printf("Keyboard received report: %d bytes\r\n", len);
	PrintHexBuf(buff, len);
	return USBH_OK;
}
