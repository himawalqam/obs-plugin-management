#include <obs-module.h>
#include <obs-frontend-api.h>
#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QVBoxLayout>
#include "opm_main_window.h"

OPMMainWindow *_opmWindow = nullptr;

OBS_DECLARE_MODULE( )
OBS_MODULE_USE_DEFAULT_LOCALE("obs-plugin-management", "en-US")

static void create_plugin_center_window() {
	QWidget *window = (QWidget *)obs_frontend_get_main_window();

	obs_frontend_push_ui_translation(obs_module_get_string);
	_opmWindow = new OPMMainWindow(window);
	obs_frontend_pop_ui_translation();
}

// Add button function
static void obs_add_plugin_button()
{
	// Get the main window of the OBS
	QWidget *mainWindow = (QWidget *)obs_frontend_get_main_window();
	if (!mainWindow) {
		return;
	}

	// Find the "Start streaming" button
	QPushButton *startStreamingButton =
		mainWindow->findChild<QPushButton *>("streamButton");
	if (!startStreamingButton) {
		return;
	}

	// Create a new button
	QPushButton *newButton =
		new QPushButton(QString(obs_module_text("opm.PluginCenter")));
	newButton->setText(QString(obs_module_text("opm.PluginCenter")));

	// Get the parent layout of the "Start streaming" button.
	QWidget *parentWidget = startStreamingButton->parentWidget();
	QVBoxLayout *layout =qobject_cast<QVBoxLayout *>(parentWidget->layout());
	if (!layout) {
		// If the layout is not vertical, create a new vertical layout.
		layout = new QVBoxLayout(parentWidget);
		parentWidget->setLayout(layout );
	}

	// Insert the new button above the Start streaming button.
	layout->insertWidget(0, newButton );

	// Set the click event for the new button
	QObject::connect(newButton, &QPushButton::clicked, []() {
		//obs_frontend_push_ui_translation(obs_module_get_string);
		blog(LOG_INFO, "plugin center is clicked!");
		if (_opmWindow) {
			_opmWindow->showOPMWindow();
		}
		//obs_frontend_pop_ui_translation();
	});
}

static void obs_event(enum obs_frontend_event event, void *)
{
	if (event == OBS_FRONTEND_EVENT_FINISHED_LOADING) {
		obs_add_plugin_button();
	} else if (event == OBS_FRONTEND_EVENT_EXIT) {
		
	}
}

MODULE_EXPORT const char *obs_module_description(void)
{
	return "OBS Plugin Management";
}

bool obs_module_load(void)
{
	blog(LOG_INFO, "obs-plugin-management loaded successfully!");

	return true;
}

void obs_module_unload(void)
{
	blog(LOG_INFO, "obs-plugin-management unloaded.");
}


void obs_module_post_load(void)
{
	if (!obs_get_module("obs-plugin-management"))
		return;

	create_plugin_center_window();

	obs_frontend_add_event_callback(obs_event, nullptr);
}
