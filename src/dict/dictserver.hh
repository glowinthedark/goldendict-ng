#ifndef __DICTSERVER_HH__INCLUDED__
#define __DICTSERVER_HH__INCLUDED__

#include "dict/dictionary.hh"
#include "config.hh"

/// Support for servers supporting DICT protocol.
namespace DictServer {

using std::vector;
using std::string;

vector< sptr< Dictionary::Class > > makeDictionaries( Config::DictServers const & servers );


class DictServerWordSearchRequestSlot: public Dictionary::WordSearchRequest
{
  Q_OBJECT


public:

public slots:
  virtual void handleResults( const QStringList & ){}
signals:
  void operate();
  void cancelSignal();
};

class DictServerWordSearchWorkerSlot: public QObject
{
  Q_OBJECT
public slots:
  virtual void run(){};

  virtual void cancel(){};
signals:
  void handleResults(const QStringList &);
  void finish();
};

} // namespace DictServer

#endif // __DICTSERVER_HH__INCLUDED__
