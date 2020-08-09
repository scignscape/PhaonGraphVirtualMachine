
// // license___here_h

#include "Dataset.h"

#include "ChannelInfo.h"


#include "bridge/qvector-matrix-r8.h"

#include <algorithm>

Dataset::Dataset(QVector_Matrix_R8* eventsFloat)
 : eventsFloat_(eventsFloat)
{
 if(eventsFloat_)
   numChannel_ = eventsFloat_->n_cols();
 else
   numChannel_ = 0;
 numPc_ = 0;

 numCompensated_ = 0;

 if(eventsFloat_)
   eventsFloatCompensated_ = new_from_dimensons();
 else
   eventsFloatCompensated_ = nullptr;

 do_preliminary_compensation();
}

void Dataset::do_preliminary_compensation()
{
 for(int r = 1; r <= eventsFloat_->n_rows(); ++r)
 {
  QVector<r8> row;
  eventsFloat_->get_row(r, row);
  
 }
}


QList<ChannelInfo*> Dataset::getChannelInfo()
{
 return channelInfo_;
}


int Dataset::getNumObservations()
{
// return eventsFloat_.size();
 return eventsFloat_->n_rows();
}


int Dataset::getNumChannels()
{
 return numCompensated_;
//  return numChannel+numPc;
}


int Dataset::getNumLengthProfiles()
{
 return lengthprofsInfo_.size();
}


QString Dataset::getName()
{
 return source_.fileName();
}

QString Dataset::get_file_source_name()
{
 // // ok?
 return source_.fileName();
}


double Dataset::getAsFloatCompensated(int obs, int indexChan)
{
 //?
 return eventsFloatCompensated_.at(obs)[indexChan];

 //return eventsFloat_->at(obs, indexChan);

 //return eventsFloat.get(obs)[indexChan];
}


QList<double> Dataset::getAsFloatCompensated(int obs)
{
 return eventsFloatCompensated_.at(obs);
//  return eventsFloat.get(obs);
}
 

// // Compute profile channels. or only one if not null
void Dataset::computeProfChannel(FacsanaduProject* proj, ProfChannel* forPc)
{
 Q_UNUSED(proj)
 Q_UNUSED(forPc)


 /*
  //If deleting or adding a channel... I find it fine enough to recompute everything. But this should
  //not be done if just modifying a gate
  HashSet<ProfChannel> oldPc=new HashSet<ProfChannel>();
  for(ChannelInfo i:channelInfo)
   if(i.pc!=null)
    oldPc.add(i.pc);
  if(!oldPc.equals(new HashSet<ProfChannel>(proj.profchan)))
   {
   //System.out.println("Recomp all chan");
   
   //Recompute all channels
   for(ChannelInfo i:new ArrayList<ChannelInfo>(channelInfo))
    if(i.pc!=null)
     channelInfo.remove(i);
   for(ProfChannel pc:proj.profchan)
    {
    ChannelInfo i=new ChannelInfo();
    i.label=pc.getName();
    i.pc=pc;
    channelInfo.add(i);
    }
   //Add new channels
   numPc=proj.profchan.size();
   resizeEvents(numChannel+numPc);
   for(int i=0;i<numPc;i++)
    {
    int toi=numChannel+i;
    ChannelInfo ci=channelInfo.get(toi);
    for(int j=0;j<getNumObservations();j++)
     {
     double[] d=eventsFloat.get(j);
     d[toi]=ci.pc.calc(lengthprofsData.get(j));
     }
    }
   }
  else if(forPc!=null)
   {
   //Update only one channel
   ChannelInfo ci=getChannelInfoForProf(forPc);
   int toi=channelInfo.indexOf(ci);
   for(int j=0;j<getNumObservations();j++)
    {
    double[] d=eventsFloat.get(j);
    d[toi]=forPc.calc(lengthprofsData.get(j));
    }
   }
  else
   {
   System.out.println("hmmm. prof chan nothing to do");
   }
*/
}

ChannelInfo* Dataset::getChannelInfoForProf(ProfChannel* pc)
{
 for(ChannelInfo* ci : channelInfo_)
 {
  if(ci->pc() == pc)
    return ci;
 }
 //throw new RuntimeException("No channel info for prof channel");
 return nullptr;
}

void Dataset::setEvents(QVector_Matrix_R8* e)  // QList<QList<double>> e)
{
 eventsFloat_ = e;
//? numChannel_ = 0;
//? if(getNumObservations() > 0)
 //?  numChannel_ = eventsFloat_.first().length();
 numChannel_ = eventsFloat_->n_cols();
}

 // // Resize the events. Used to make space for virtual channels
void Dataset::resizeEvents(int newsize)
{
 QList<QList<double>> newEventsFloat; // =new ArrayList<double[]>(eventsFloat.size());

/*
 for(QList<double> o : eventsFloat_)
 {
  QVector<double> n(newsize); // =new double[newsize];
  std::copy_n(o.begin(), numChannel_, n.begin());

  //?System.arraycopy(o, 0, n, 0, numChannel);
  newEventsFloat.push_back(n.toList());
 }
  //? eventsFloat_ = newEventsFloat;
 */

}


