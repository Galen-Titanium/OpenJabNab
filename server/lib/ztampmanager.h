#ifndef _ZTAMPMANAGER_H_
#define _ZTAMPMANAGER_H_

#include <QHash>
#include <QVector>
#include "global.h"
#include "apihandler.h"
#include "apimanager.h"
#include "ztamp.h"

class Account;
class Ztamp;
class HTTPRequest;
class PluginInterface;
class OJN_EXPORT ZtampManager : public ApiHandler<ZtampManager>
{
	friend class PluginAuth;
	friend class ApiManager;
	friend class PluginManager;
public:
	static ZtampManager & Instance();

	static Ztamp * GetZtamp(PluginInterface *, QByteArray const&);
	static void PluginStateChanged(PluginInterface *);
	static inline void Init() { InitApiCalls(); };
	static void Close();

	// API
	static void InitApiCalls();

protected:
	static Ztamp * GetZtamp(QByteArray const&);
	static QVector<Ztamp *> GetZtamps();
	static void PluginLoaded(PluginInterface *);
	static void PluginUnloaded(PluginInterface *);

	// API
	API_CALL(Api_GetListOfZtamps);

private:
	ZtampManager();
	static QHash<QByteArray, Ztamp *> listOfZtamps;
};

#endif
