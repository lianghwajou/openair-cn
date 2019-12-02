/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under 
 * the Apache License, Version 2.0  (the "License"); you may not use this file
 * except in compliance with the License.  
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef REMOTE_UE_IP_INFORMATION_SEEN
#define REMOTE_UE_IP_INFORMATION_SEEN

#define REMOTE_UE_IP_INFORMATION_MINIMUM_LENGTH 2
#define REMOTE_UE_IP_INFORMATION_MAXIMUM_LENGTH 5

typedef struct remote_ue_ip_information_s{
    uint8_t spare:5;
    #define ADDRESS_TYPE_IPV4 0b001
    #define ADDRESS_TYPE_IPV6 0b010
    uint8_t addresstype:3;
    #define REMOTE_UE_IP_ADDRESS
    union{
      struct in_addr *ipv4;
      struct in6_addr *ipv6;  
    }remoteueipaddress;
}remote_ue_ip_information_t;

int encode_remote_ue_ip_information(remote_ue_ip_information_t *remoteueipinformation, uint8_t *buffer, uint8_t iei, uint32_t len);
int decode_remote_ue_ip_information(remote_ue_ip_information_t *remoteueipinformation, uint8_t *buffer, uint8_t iei, uint32_t len);

#endif 