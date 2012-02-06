/*  
 *
 *  Copyright (C) 2005 Kemal Ilgar Eroglu <kieroglu@math.washington.edu>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */


#define 	UPDATE_INTERVAL 2000 			/* Countdown update period in 
							   milliseconds */

typedef struct {
  GtkWidget 	*eventbox,				/* Main container widget
		 					   in ctrl->base */
		*box,					/* v/hbox that holds pbar */  
		*pbar, 					/* Progress bar */
		*tree, 					/* Treeview */
		*buttonadd,*buttonedit,*buttonremove,	/* options window buttons */
		*buttonup, *buttondown,
		*spin_repeat, *spin_interval,		/* spinbuttons for alarm repeat */
		*menu,
		*repeat_alarm_box;			/* Box holding the repeat 
							   alarm settings */
		
  XfcePanelPlugin *base;				/* The plugin widget */
  GtkListStore *list;					/* The alarms list */
  gint 		count,					/* Nubmer of alarms */
		selected,
		timeout_period_in_sec,			/* Active countdown period */
		repetitions,				/* Number of alarm repeats */
		rem_repetitions,			/* Remaining repeats */
		repeat_interval;			/* Time interval between
							   repeats (in secs) */
  guint 	timeout,repeat_timeout;			/* The timeout IDs */
  gboolean 	timer_on,				/* TRUE if countdown 
							   is in progress */
		nowin_if_alarm,				/* Show warning window when
							   alarm command is set */
		repeat_alarm,				/* Repeat alarm */
		alarm_repeating,			/* True while alarm repeats */
		is_paused,					/* True if the countdown is paused */
		is_countdown;				/* True if the alarm type is contdown */
  GtkTooltips 	*tip;					/* Tooltip for panel */
  GArray 	*menuarray;				/* Array of popup 
							   menuitems (alarms). These 
							   are used to find the index
							   of the selected menuitem. */
  gchar 	*timeout_command,			/* Command when countdown ends */
  			*configfile;			/* Full address of the permanent
  									config file -- this is not the
  									plugin rc file. */
  GTimer 	*timer;					/* Keeps time elapsed */

} plugin_data;

typedef struct {
  GtkSpinButton	*timeh,*times,*timem,			/* Spinbuttons for h-m-s 
							   format */
		*time_h,*time_m;			/* Spinbuttons for 24h format */
  GtkEntry 	*name,*command;				/* Name, and command entries */
  GtkRadioButton *rb1;					/* Radio button for the
							   h-m-s format */
  GtkWindow 	*window;				/* Add/Edit window */
  plugin_data 	*pd;					/* Plugin data */
} alarm_data;
