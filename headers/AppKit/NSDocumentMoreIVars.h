//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

#import <objc/NSObject.h>

@class NSArray, NSConditionLock, NSDate, NSDocument, NSError, NSFileVersion, NSMutableArray, NSNumber, NSOperationQueue, NSPersonNameComponents, NSPointerArray, NSSavePanel, NSString, NSTimer, NSURL, _NSDocumentActivity, _NSDocumentFileAccess;
@protocol NSDocumentAlternateContents, OS_dispatch_queue;

__attribute__((visibility("hidden")))
@interface NSDocumentMoreIVars : NSObject
{
    long long documentUniquingNumber;
    NSString *originalDisplayName;
    NSNumber *originalParentFolderID;
    NSString *originalFileName;
    NSDate *fileModificationDate;
    NSNumber *savePanelNameExtensionHidden;
    NSArray *savePanelTagNames;
    NSObject<OS_dispatch_queue> *activityQueue;
    _NSDocumentActivity *activityBeingPerformed;
    NSMutableArray *pendingActivities;
    BOOL activityIsContinuing;
    NSObject<OS_dispatch_queue> *fileAccessQueue;
    _NSDocumentFileAccess *fileAccessBeingPerformed;
    NSMutableArray *pendingFileAccess;
    NSOperationQueue *filePresenterQueue;
    NSString *providerPurposeIdentifier;
    CDStruct_df2dc5d0 differenceDueToRecentChanges;
    CDStruct_df2dc5d0 differenceSincePreservingPreviousVersion;
    CDStruct_df2dc5d0 differenceSinceSaving;
    CDStruct_df2dc5d0 differenceSinceAutosaving;
    CDStruct_df2dc5d0 differenceDueToDiscardableChanges;
    CDStruct_df2dc5d0 differenceDueToExplicitChanges;
    BOOL appearsLocked;
    BOOL autosavingPossibilityIsChecked;
    BOOL autosavingSafetyIsChecked;
    BOOL advisoryAutosavingSafetyIsChecked;
    NSMutableArray *autosavingCheckChangeCounts;
    BOOL autosavingSafetyCheckingIsDisabled;
    BOOL autosavingCheckingIsDisabledForScripting;
    BOOL autosavingCheckingIsDisabledForSaving;
    BOOL automaticDuplicateIsChecked;
    BOOL needsAutomaticDuplicate;
    CDUnknownBlockType autosavingCheckWaiter;
    NSPointerArray *editors;
    BOOL waitingForEditorCommiting;
    CDUnknownBlockType editorCommittingWaiter;
    BOOL disabledSuddenTermination;
    NSSavePanel *savePanel;
    NSTimer *autosavingTimer;
    BOOL isAutosavingBecauseOfTimer;
    BOOL deferredTimerScheduling;
    BOOL autosavingIsImplicitlyCancellable;
    NSURL *autosavedContentsFileURL;
    BOOL autosavingPeriodicallyIsDisabled;
    id eventMonitor;
    double firstUnsavedChangeTime;
    double lastUnsavedChangeTime;
    unsigned long long fileContentsPreservationReason;
    NSString *fileContentsComment;
    id temporaryVersionStorageIdentifier;
    BOOL hasPreservedVersionInTemporaryStorage;
    double lastPreservationTime;
    NSFileVersion *versionWithoutRecentChanges;
    BOOL versionWithoutRecentChangesIsNotLastOpened;
    NSFileVersion *lastOpenedVersion;
    NSFileVersion *previousSavedVersion;
    BOOL scheduledCleanupOldVersions;
    long long cleanupOldVersionsDisableCount;
    NSObject<OS_dispatch_queue> *previousSavedVersionLookupQueue;
    BOOL previousSavedVersionIsChecked;
    NSFileVersion *mostRecentPreservedVersion;
    struct __CFSet *javaVariantMethodsBeingInvoked;
    NSError *javaLastError;
    BOOL updateFileWrapperNamesDuringWriting;
    NSURL *originalContentsURLDuringWriting;
    NSConditionLock *userInteractionLock;
    NSFileVersion *oldVersion;
    NSDocument *originalDocument;
    BOOL savingWhileClosing;
    int autoID;
    BOOL ignoreUndoAndRedoNotifications;
    BOOL isHandlingConflicts;
    BOOL conflictHandlingSheetIsUp;
    BOOL didUpdateAfterReverting;
    unsigned long long autosaveElsewhereReason;
    NSError *mostRecentAutosavingError;
    BOOL hasPresentedMostRecentAutosavingError;
    long long diskFullRecoveryAttempts;
    BOOL isWaitingForWriter;
    NSURL *newFileURL;
    BOOL didChange;
    BOOL didBecomeDisconnected;
    BOOL accommodatedDeletion;
    NSURL *backupFileURL;
    NSError *temporaryVersionStorageRequirementError;
    BOOL shouldSkipTemporaryVersionStorageAlert;
    BOOL userClickedDontSaveInLastRunSavePanel;
    BOOL isDraft;
    BOOL isDuplicate;
    BOOL suppressWindowTitleDisplayNameEmbellishment;
    BOOL isAutoDuplicate;
    BOOL isAutoDuplicateFromEmailAttachment;
    NSURL *originalDocumentURL;
    NSURL *duplicateDocumentDestinationURL;
    NSURL *autoDuplicateOriginalDocumentURL;
    BOOL isAutosaveAsDisabled;
    BOOL readInitialContents;
    NSArray *nonModalErrors;
    long long versionsButtonTransactionCount;
    BOOL showAutosaveButton;
    NSArray *tagNames;
    BOOL suppressSettingFileIsDraft;
    long long fileURLSandboxExtensionToken;
    unsigned int recentDocumentID;
    id <NSDocumentAlternateContents> alternateContents;
    unsigned long long alternateContentsDisassociationReason;
    unsigned long long sharingState;
    NSPersonNameComponents *sharingOwnerNameComponents;
    BOOL forciblyEnableSaveAsShouldRevertOption;
}

@property unsigned int recentDocumentID; // @synthesize recentDocumentID;
- (id)description;

@end

