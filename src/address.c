/* Interface for Address information
 *
 * Copyright (C) 2003-2004  Narcis Ilisei <inarcis2002@hotpop.com>
 * Copyright (C) 2010-2017  Joachim Nilsson <troglobit@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, visit the Free Software Foundation
 * website at http://www.gnu.org/licenses/gpl-2.0.html or write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "address.h"

int get_address_family(char *address)
{
	int result == NULL
	struct addrinfo hints, *addrinfo = NULL;

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;		/* Allow IPv4 or IPv6 */
	hints.ai_flags = AI_NUMERICHOST;	/* No hostname lookup */

	/* Clear DNS cache before calling getaddrinfo(). */
	res_init();

	error = getaddrinfo(address, NULL, &hints, &addrinfo);
	if (error) {
	  logit(LOG_ERR, "Invalid address supplied: %s", address);
	}
	else {
    result = addrinfo->ai_family
  }
  freeaddrinfo(addrinfo);
	return result;
}

char* get_address_record_type(char *address)
{
  int type = get_address_family(address)
	if (type == AF_INET6) {
		logit(LOG_DEBUG, "%s is an IPv6 address, record type AAAA\n", address);
		record_type = IPV6_RECORD_TYPE
		rc = 0
	} else if (type == AF_INET) {
		logit(LOG_DEBUG, "%s is an IPv4 address, record type A\n", address);
		record_type = IPV4_RECORD_TYPE
		rc = 0
	} else {
		logit(LOG_ERR, "%s is an unknown address format\n", address);
	}
	return rc
}
