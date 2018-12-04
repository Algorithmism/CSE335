/**
 * \file Picture.h
 *
 * \author Charles B. Owen
 *
 * \brief The picture we are drawing
 */
#pragma once

#include <vector>
#include "PictureObserver.h"
#include "Timeline.h"
#include "MachineAdapter.h"

class CActor;

/**
 * \brief The picture we are drawing.
 *
 * There will be one picture object that contains all of 
 * our actors, which then contains the drawables. 
 */
class CPicture
{
public:

	/** Constructor */
    CPicture();
	/** Virtual Destructor */
    virtual ~CPicture();

	/** \brief Copy Constructor */
    CPicture(const CPicture &) = delete;

	/** \brief Assignment operator(disabled)
	 * \return delete*/
    CPicture &operator=(const CPicture &) = delete;

    /** \brief The picture size
     * \return Size */
    Gdiplus::Size GetSize() { return mSize; }

    /** \brief The picture size
     * \param size The new picture size */
    void SetSize(Gdiplus::Size size) { mSize = size; }

	/** \brief Add the Observer
	 *	\param *observer */
    void AddObserver(CPictureObserver *observer);
	/** \brief Removing the Observer
	 *	\param *observer */
    void RemoveObserver(CPictureObserver *observer);

	/** \brief Updating the Observers */
    void UpdateObservers();
	
	/** \brief Draw
	 *	\param *graphics */
    void Draw(Gdiplus::Graphics *graphics);
	
	/** \brief Add the Actor
	 *	\param actor */
    void AddActor(std::shared_ptr<CActor> actor);
	
	/** \brief Save
	 *	\param filename */
    void Save(const std::wstring &filename);
	
	/** \brief Load
	 *	\param filename */
    void Load(const std::wstring &filename);
	
	/** Get the machine 
	 * \return mMachine */
	std::shared_ptr<CMachine> GetMachine() { return mMachine; }
	
	/** Get the machine
	 * \return mMachine */
	std::shared_ptr<CMachine> GetMachine2() { return mMachine2; }
	
	/** \brief Setting the Source
	 *	\param machine */
	void SetMachine(std::shared_ptr<CMachine> machine) { mMachine = machine; }
	
	/** \brief Setting the Source
	 *	\param machine */
	void SetMachine2(std::shared_ptr<CMachine> machine) { mMachine2 = machine; }
    /** \brief Iterator that iterates over the actors in a picture */
    class ActorIter
    {
    public:
        /** \brief Constructor
        * \param picture Picture we are iterating
        * \param pos Starting position */
        ActorIter(CPicture *picture, int pos) : mPicture(picture), mPos(pos) {}

        /** \brief Test for end of the iterator
        * \param other Other object to test against
        * \returns True if we this position equals not equal to the other position */
        bool operator!=(const ActorIter &other) const
        {
            return mPos != other.mPos;
        }

        /** \brief Get value at current position
        * \returns Value at mPos in the collection */
        std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

        /** \brief Increment the iterator
        * \returns Reference to this iterator */
        const ActorIter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        CPicture *mPicture; ///< Picture we are iterating over
        int mPos;           ///< Position in the collection
    };

    /** \brief Get an iterator for the beginning of the collection
    * \returns Iter object at position 0 */
    ActorIter begin() { return ActorIter(this, 0); }

    /** \brief Get an iterator for the end of the collection
    * \returns Iter object at position past the end */
    ActorIter end() { return ActorIter(this, mActors.size()); }

    /** \brief Get a pointer to the Timeline object
    * \returns Pointer to the Timeline object */
    CTimeline *GetTimeline() { return &mTimeline; }
	
	/** \brief Setting the Source
	 *	\param time */
    void SetAnimationTime(double time);

	/** \brief Get the animation time */
    double GetAnimationTime();

	/** \brief Get Machine Adapter
	 *	\return mMachineAdapter */
	std::shared_ptr<CMachineAdapter> GetMachineAdapter() { return mMachineAdapter; }
	
	/** \brief Get the Machine Adapter
	 *	\return mMachineAdapter2 */
	std::shared_ptr<CMachineAdapter> GetMachineAdapter2() { return mMachineAdapter2; }
	
	/** \brief Setting the Machine Adapter
	 *	\param adapter */
	void SetMachineAdapter(std::shared_ptr<CMachineAdapter> adapter);
	
	/** \brief Setting the Machine Adapter
	 *	\param adapter2 */
	void SetMachineAdapter2(std::shared_ptr<CMachineAdapter> adapter2);

private:

    Gdiplus::Size mSize = Gdiplus::Size(800, 600); ///< mSize


    std::vector<CPictureObserver *> mObservers; ///< mObservers

    std::vector<std::shared_ptr<CActor>> mActors; ///< mActors
	/** \brief Default constructor disabled */

    CTimeline mTimeline; ///< mTimeline

	std::shared_ptr<CMachine> mMachine; ///< mMachine

	std::shared_ptr<CMachine> mMachine2; ///< mMachine2

	std::shared_ptr<CMachineAdapter> mMachineAdapter; ///<mMachineAdapter

	std::shared_ptr<CMachineAdapter> mMachineAdapter2; ///<mMachineAdapter2
};

